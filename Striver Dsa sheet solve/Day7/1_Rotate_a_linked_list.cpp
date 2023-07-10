#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};
// brute force not optimal for large value of k
// Time Complexity: O(Number of nodes present in the list*k)
// Space Complexity: O(1)
node *rotateRight(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// optimal solution
// Time Complexity: O(length of list) + O(length of list – (length of list%k))Space Complexity: O(1)
// Space Complexity: O(1)
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    int length = 1;
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % length;
    int end = length - k;
    while (end--)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}