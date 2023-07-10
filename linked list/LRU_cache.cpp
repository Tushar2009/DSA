#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev=NULL;
    Node(int k,int v)
    {
        key=k;
        value=v;
        next=prev=NULL;
    }
};
class LRUCache
{
    public:
    unordered_map<int,Node*> map;
    Node *head,*tail;
    int capacity,count;

    LRUCache(int c)
    {
        capacity=c;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
        count=0;
    }
    void deleteNode(Node *node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void addtoHead(Node *node)
    {
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    int get(int key)
    {
        if (map[key] != NULL) { 
			Node *node = map[key]; 
			int result = node->value; 
			deleteNode(node); 
			addtoHead(node); 
			return result; 
		} 
		return -1;
    }
    void set(int key, int value) 
	{  
		if (map[key] != NULL) { 
			Node *node = map[key]; 
			node->value = value; 
			deleteNode(node); 
			addtoHead(node); 
		} 
		else { 
			Node *node = new Node(key, value); 
			map[key]= node; 
			if (count < capacity) { 
				count++; 
				addtoHead(node); 
			} 
			else { 
				map.erase(tail->prev->key); 
				deleteNode(tail->prev); 
				addtoHead(node); 
			} 
		} 
	}

};
int main()
{
    LRUCache cache(4);
    cache.set(1,10);
    cout<<"Value for key 1 is :"<<cache.get(1)<<endl;
    cache.set(2,20);
    cache.set(3,10);
    cache.set(4,30);
    cache.set(5,40);
    cache.set(6,50);
    cache.set(7,30);
    cache.set(8,40);
    cache.set(9,60);
    cache.set(10,30);
    cout<<"Value for key 10 is :"<<cache.get(10)<<endl;
    return 0;
}