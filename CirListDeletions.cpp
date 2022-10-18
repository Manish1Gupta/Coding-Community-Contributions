#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
void Traversal(Node* n)
{
    Node* temp=n;
    do
    {
        cout<<n->data<<" ";
        n=n->next;
    } while (n!=temp);
}
void DeleteAtStart(Node** head,Node* n)
{
    Node* temp=(n->next)->next;
    n->next=temp;
    *head=n->next;
}
void DeleteAtGivenNode(Node* n,int pos)
{
    int c=1;
    while(c!=pos-1)
    {
        n=n->next;
        c++;
    }
    Node*temp=(n->next)->next;
    n->next=temp;
    temp=NULL;
}
void DeleteAtEnd(Node* n)
{
    Node* p=n;
    while((n->next)->next!=p)
    {
        n=n->next;
    }
    n->next=p;
}
int main()
{
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    Node* last=new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=last;

    last->data=4;
    last->next=head;

    int ch;
    cout<<"Enter choice:\n1.Delete At the Beginning of Circular Linked List.\n2.Delete At a Given Position of Circular Linked List.\n3.Delete At the End of Circular Linked List.\n";
    cin>>ch;
    switch(ch)
    {
        case 1:Traversal(head);
               cout<<"\n";
               DeleteAtStart(&head,last);
               Traversal(head);
               break;
        case 2:int pos;
               cout<<"Enter position at which you want to delete data \n";
               cin>>pos;
               Traversal(head);
               cout<<"\n";
               DeleteAtGivenNode(head,pos);
               Traversal(head);
               break;
        case 3:Traversal(head);
               cout<<"\n";
               DeleteAtEnd(head);
               Traversal(head);
               break;
        default:cout<<"Enter Valid Choice";   
    }
}
