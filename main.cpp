/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method*/
Node * deleteK(Node *head,int k)
{
  //Your code here
  Node *h= head;
  Node *nxt,*prev;int i;
  if(k==1){
      free(head);
      return NULL;
  }
  while(1){
      i=0;
      if(h==NULL)
        break;
    while(i<k-1 && h!=NULL){

        prev=h;
        h=h->next;
        i++;

    }

    if(h!=NULL && i==k-1){
        //printf("ji");
        nxt=h->next;
        prev->next=nxt;
        free(h);
        h=nxt;
    }
  }

  return head;
}
