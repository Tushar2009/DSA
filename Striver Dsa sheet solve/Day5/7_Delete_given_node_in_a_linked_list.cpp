
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Time Complexity: O(1)
// Space Complexity: O(1)
void deleteNode(LinkedListNode<int> *node)
{
    // Write your code here.
    node->data = node->next->data;
    node->next = node->next->next;
    return;
}