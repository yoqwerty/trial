

bool fun(Node *node,int sum,int s){

  if(node->left==NULL&&node->right==NULL){
      s+=node->data;
      if(s==sum)

      return true;
  }
  bool ans=0;
  if(node!=NULL)
  s+=node->data;

  //printf("%d sum ",s);
  if(node->left && s<=sum)ans=ans|| fun(node->left,sum,s);
  if(node->right && s<=sum)ans=ans|| fun(node->right,sum,s);
    return ans;

}

bool hasPathSum(Node *node, int sum)
{
   return fun(node,sum,0);

}
