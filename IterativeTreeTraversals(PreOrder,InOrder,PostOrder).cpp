#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node
{
    public:
    int key;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* temp = new Node();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void InOrderTraversal(Node* root)
{
    stack<Node*> s;
    Node* curr=root;
    while(curr != NULL || s.empty()==false)
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }   
}
void PreOrderTraversal(Node* root)
{
    stack<Node*> s;
    s.push(root);
    while(s.empty()==false)
    {
        Node* curr = s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right != NULL)
        s.push(curr->right);
        if(curr->left != NULL)
        s.push(curr->left);
    }
}
void SpiralOrderTraversal(Node* root)
{
    if(root==NULL)
    return;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    bool reverse = false;
    while(!q.empty())
    {
        int l = q.size();
        for(int i=0;i<l;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(reverse)
               s.push(curr);
            else
               cout<<curr->key<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        if(reverse)
        {
            while(!s.empty())
            {
                cout<<s.top()->key<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<"\n";
    }

}
int main()
{
    Node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(30);
    root->left->right = newNode(40);
    root->left->right->left = newNode(50);
    root->left->right->left->right = newNode(60);
    root->right = newNode(70);
    root->right->left = newNode(80);
    root->right->right = newNode(90);
    root->right->right->left = newNode(100);
    root->right->right->right = newNode(110);
    InOrderTraversal(root);
    cout<<"\n";
    PreOrderTraversal(root);
    cout<<"\n";
    SpiralOrderTraversal(root);
}