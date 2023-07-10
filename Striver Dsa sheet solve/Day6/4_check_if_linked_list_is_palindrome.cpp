#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Time Complexity: O(N/2)+O(N/2)+O(N/2)
// Space Complexity: O(1)
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    ListNode *dummy = head;
    while (slow != NULL)
    {
        if (dummy->val != slow->val)
            return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}