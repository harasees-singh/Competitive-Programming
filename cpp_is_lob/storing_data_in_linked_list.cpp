#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
};
void InsertAtTail(node* &head, int val)
{
    node* pointer_to_node_to_be_inserted = new node(val);

    if(head == NULL)
    {
        head = pointer_to_node_to_be_inserted;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = pointer_to_node_to_be_inserted;
}
node* Search(node* head, int val)
{
    node* temp=head;
    while(temp->next != NULL)
    {
        if(temp->next->data == val)
        {
            return temp->next;
        }
        temp=temp->next;
    }
    return NULL;
}
void InsertAtHead(node* &head, int val) // taking in head's reference because we will be making head to point to a different node
{
    node* n = new node(val);
    n->next = head;
    head = n;
}
void Delete(node* head, int val)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->data==val)
        {
            temp->next = temp->next->next;   
            break;
        }
        temp=temp->next;
    }
}
void Display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    node start(5);
    node* head = &start;
    InsertAtHead(head, 4);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    InsertAtTail(head, 8);
    Display(head);

    // taking input
    int t = 4;
    node new_start(0);
    node* new_head = &new_start;
    node* temp = new_head;
    while(t--)
    {
        int val;
        cin >> val;
        node* n = new node(val);
        temp->next = n;
        temp = n;
    }
    Display(new_head);
    int n = 4;
    node* head_again = NULL;
    for(int i =0; i<n; i++)
    {
        InsertAtTail(head_again, i+2);
    }
    Delete(head_again, 5);
    cout << Search(head_again, 4) << endl;          // returns the address of the node in which we have stored 4
    Display(head_again);
    return 0;
}