
int sum(Node* node){

    if(node==NULL){
        return 0;
    }
    return (node->data+sum(node->left)+sum(node->right));
}
bool isSumTree(Node* node)
{
     // Your code here
     if(node==NULL ||(node->left==NULL&&node->right==NULL)){
         return true;
     }

    if(node->data==(sum(node->left) + sum(node->right))){
         return (isSumTree(node->left) && isSumTree(node->right));
     }

         return false;

}
