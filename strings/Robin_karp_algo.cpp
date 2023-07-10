#include <bits/stdc++.h> 
using namespace std; 
//here modulo is taken to minimize the size of hash values
//value of q should be prime and should be greater
#define d 256
const int q=101;
void RBsearch(string pat,string txt,int M, int N)
{
    int h=1;
    //Compute (d^(M-1))%q
    for(int i=1;i<=M-1;i++)
    {
        h=(h*d)%q;
    }
    //Compute p and t0 hash values
    int p=0,t=0;
    for(int i=0;i<M;i++) 
    {
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    for(int i=0;i<=N-M;i++)
    {
        //Check for hit
        if(p==t)
        {
            bool flag=true;
            for(int j=0;j<M;j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)cout<<i<<" ";
        }
         //Compute ti+1 using ti
        if(i<N-M)
        {
            //Rolling Hash 
            t=((d*(t-txt[i]*h))+txt[i+M])%q;
        }
        //This is done so that sum of hash value of txt should  not become -ve at some computation
        if(t<0)t=t+q;
    }

}
int main() 
{ 
    string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    cout<<"All index numbers where pattern found:"<<" ";
    RBsearch(pat,txt,4,15);
    
    return 0; 
} 