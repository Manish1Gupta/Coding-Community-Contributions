#include <iostream>
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
    temp->left = temp->right = NULL;
    return temp;
}
void preorder(Node* root)
{
        if (root != NULL)
        {
            cout<<(root->key)<<" ";
            preorder(root->left);
            preorder(root->right);
        }
}
void inorder(Node* root)
{
        if (root != NULL)
        {
            inorder(root->left);
            cout<<(root->key)<<" ";
            inorder(root->right);
        }
}
void postorder(Node* root)
{
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<(root->key)<<" ";
        }
}
void levelOrderTraversal(Node* root)
{
    if(root==NULL)
    cout<<"Zero Element Tree";
    else
    {
        queue<Node*> a;
        a.push(root);
        while(a.empty()==false)
        {
            Node* p = a.front();
            a.pop();
            cout<<(p->key)<<" ";
            if(p->left != NULL)
            a.push(p->left);
            if(p->right != NULL)
            a.push(p->right);
        }
    }
}
void LevelOrderTraversal(Node* root)
{
    if(root==NULL)
    return;
    else
    {
        queue<Node*> a;
        a.push(root);
        while(a.empty()==false)
        {
            int q = a.size();
            for(int i=0;i<q;i++)
            {
                Node* p = a.front();
                a.pop();
                cout<<(p->key)<<" ";
                if(p->left != NULL)
                a.push(p->left);
                if(p->right != NULL)
                a.push(p->right);
            }
        }
    }
}
void leftView(Node* root)
{
    if(root==NULL)
    return;
    else
    {
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int k=q.size();
            Node* a;
            for(int i=0;i<k;i++)
            {
                a=q.front();
                q.pop();
                if(i==0)
                cout<<a->key<<" ";
                if(a->left!=NULL)
                q.push(a->left);
                if(a->right!=NULL)
                q.push(a->right);
            }
        }
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
    int ch;
    cout<<"Press:-\n1 for Pre-Order Traversal\n2 for In-Order Traversal\n3 for Post-Order Traversal\n4 for Level-Order Traversal(Method 1)\n5 for Level-Order Traversal(Method 2)\n6 for Left View of the tree\n";
    cin>>ch;
    switch(ch)
    {
        case 1 : preorder(root);
                 break;
        case 2 : inorder(root);
                 break;
        case 3 : postorder(root);
                 break;
        case 4 : levelOrderTraversal(root);
                 break;
        case 5 : LevelOrderTraversal(root);
                 break;
        case 6 : leftView(root);
                 break;
        default : cout<<"Invalid Choice";
    }
}