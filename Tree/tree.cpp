#include <iostream>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
Node *CreateANode(int data)
{
    Node *NewNode = new Node(data);
    return NewNode;
}
int main()
{

/*
                5
          /          \
        7             11
     /    \         /     \
   15     20      4       3
  /  \   /  \             /  \
25   23 85   27         10    32
                                /  \
                              31    30
*/                              
    Node *root = CreateANode(5);
    root->left = CreateANode(7);
    root->left->left = CreateANode(15);
    root->left->left->left = CreateANode(25);
    root->left->left->right = CreateANode(23);
    root->left->right = CreateANode(20);
    root->left->right->left = CreateANode(85);
    root->left->right->right = CreateANode(27);
    root->right = CreateANode(11);
    root->right->left = CreateANode(4);
    root->right->right = CreateANode(3);
    root->right->right->left = CreateANode(10);
    root->right->right->right = CreateANode(32);
    root->right->right->right->left = CreateANode(31);
    root->right->right->right->right = CreateANode(30);
    Inorder(root);
    return 0;
}