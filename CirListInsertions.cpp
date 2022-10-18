#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
int Length(Node* n)
{
    int c=1;
    Node* temp=n;
    do
    {
        cout<<n->data<<" ";
        c++;
        n=n->next;
    } while (n!=temp);
    return c;
}
void Traversal(Node* n)
{
    Node* temp=n;
    do
    {
        cout<<n->data<<" ";
        n=n->next;
    } while (n!=temp);
}
void InsertAtStart(Node* n,Node** head,int a)
{
    Node* new_node=new Node();
    new_node->data=a;
    Node* temp=n->next;
    n->next=new_node;
    new_node->next=temp;
    *head=n->next;
}
void InsertAtGivenNode(Node* n,int a,int pos)
{
    int c=1;
    Node* new_node=new Node();
    new_node->data=a;
        while(c!=pos-1)
        {
           n=n->next;
           c++;
        }
        Node* temp=n->next;
        n->next=new_node;
        new_node->next=temp;
}
void InsertAtEnd(Node* n,int a)
{
    Node* new_node=new Node();
    new_node->data=a;
    Node* temp=n->next;
    n->next=new_node;
    new_node->next=temp;
}
int main()
{
    Node* head=NULL;
    Node* second=NULL;
    Node* third=NULL;
    Node* last=NULL;

    head=new Node();
    second=new Node();
    third=new Node();
    last=new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third; 

    third->data=3;
    third->next=last;

    last->data=4;
    last->next=head;

    int ab;
    cout<<"Enter data to be inserted \n";
    cin>>ab;

    int ch;
    cout<<"Enter choice:\n1.Insert At the Beginning of Circular Linked List.\n2.Insert At a Given Position of Circular Linked List.\n3.Insert At the End of Circular Linked List.\n";
    cin>>ch;
    switch(ch)
    {
        case 1:Traversal(head);
               cout<<"\n";
               InsertAtStart(last,&head,ab);
               Traversal(head);
               break;
        case 2:int pos;
               cout<<"Enter position at which you want to insert data \n";
               cin>>pos;
               Traversal(head);
               cout<<"\n";
               InsertAtGivenNode(head,ab,pos);
               Traversal(head);
               break;
        case 3:Traversal(head);
               cout<<"\n";
               InsertAtEnd(last,ab);
               Traversal(head);
               break;
        default:cout<<"Enter Valid Choice";   
    }
}