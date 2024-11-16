#include<iostream>
using namespace std;
class Node{
    public:
    Node*left;
    int data;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
  
};
  void Preorder(Node* root)
  {
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
  }
  void PostOrder(Node*root)
  {
    if(root==NULL)
    return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
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
    Node* root = CreateANode(6);
    root->left = CreateANode(2);
    root->right = CreateANode(5);
    root->left->left = CreateANode(1);
    root->left->right = CreateANode(4);
    root->right->left = CreateANode(3);
    root->right->right = CreateANode(2);
    Inorder(root);
    cout<<"\n";
    PostOrder(root);
    cout<<"\n";
    Inorder(root);


    return 0;
}