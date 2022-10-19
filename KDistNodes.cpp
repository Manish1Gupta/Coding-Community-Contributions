#include <iostream>
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
    Node* p = new Node();
    p->key = data;
    p->left = p->right = NULL;
    return p;
}
void KDistNodes(Node* root,int k)
{
    if(root = NULL)
    return;
    if(k==0)
    cout<<(root->key)<<" ";
    else
    {
       KDistNodes(root->left,k-1);
       KDistNodes(root->right,k-1);
    }
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    KDistNodes(root,2);
}