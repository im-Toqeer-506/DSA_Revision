#include<iostream>
using namespace std;
class Node{
    public:
    Node*left;
    int data;
    Node*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
  void Inorder(Node*root)
{
    if(root==NULL)
    return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}
  Node* CreateANode(int data)
    {
    Node* NewNode=new Node(data);
    return NewNode;

    }
int main()
{
    Node* root = CreateANode(9);
    root->left = CreateANode(4);
    root->right = CreateANode(11);
    root->left->left = CreateANode(2);
    root->left->right = CreateANode(7);
    root->right->right = CreateANode(2);
    root->right->right=CreateANode(15);
    root->right->right->left=CreateANode(14);
    root->left->right->left=CreateANode(5);
    root->left->right->right=CreateANode(8);
    cout<<"Inorder: ";
    Inorder(root);
    return 0;
}