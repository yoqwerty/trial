/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be 1 for following tree.
         20
     /      \
   10       30
  and return value should be 0 for following tree.
         10
     /      \
   20       30 */


bool BST(Node* root,Node **prev) {
    // Your code here
   // if(root==NULL)return true;
    if(root){
    if (!BST(root->left,prev))return false;
    if(*prev!=NULL && root->data <=(*prev)->data)
    return false;
    *prev=root;
    return BST(root->right,prev);
    }
    else
    return true;
}
bool isBST(Node* root){
    Node *prev=NULL;
    return BST(root,&prev);
}

