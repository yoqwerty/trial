/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
    Node *sp=head,*fp=head;
    if(head==NULL){
        return -1;
    }
    while(fp && fp->next){
        sp=sp->next;

        fp=fp->next->next;
    }
   return sp->data;
}
