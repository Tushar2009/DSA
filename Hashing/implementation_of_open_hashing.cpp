#include<bits/stdc++.h>
using namespace std;
struct myHash
{
    int *arr,cap,size;
    myHash(int c)
    {
        cap=c;
        size=0;
        for(int i=0;i<cap;i++)
        {
            arr[i]=-1;
        }
    }
    int hash(int key)
    {
        return (key%cap);
    }
    // linear probing
    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
            {
                return false;
            }
        }
        return false;
    }
    bool insert(int key)
    {
        if(size==cap)return false;
        int i=hash(key);
        //here -1 = is for element not present
        //     -2 = is for any deleted element
        //this loop performs the linear probing untill free slot in array is found or any deleted element slot is found or element is already present
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
        {
            i=(i+1)%cap;
        }
        if(arr[i]==key)
        {
            return false;
        }
        else
        {
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool erase(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
            {
                arr[i]=-2;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
            {
                return false;
            }
        }
        return false;
    }

};
	int main() 
	{ 
	    myHash mh(7);
	    mh.insert(49);
	    mh.insert(56);
	    mh.insert(72);
	    if(mh.search(56)==true)
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	    mh.erase(56);
	    if(mh.search(56)==true)
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	} 
