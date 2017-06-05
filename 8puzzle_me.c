#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct node
{
	int mat[3][3];
	int cost,x,y;
    struct node *par,*next;
};
int itemCount = 0;
struct node* pq[MAX];
void insert(struct node *p){
   int i = 0;

   if(!isFull()){
      // if queue is empty, insert the data 
		
      if(itemCount == 0){
         //intArray[itemCount++] = data;  
		 pq[itemCount++]=p;      
      }else{
         // start from the right end of the queue 
         for(i = itemCount - 1; i >= 0; i-- ){
            // if data is larger, shift existing item to right end 
            if(p->cost<pq[i]->cost){
               pq[i+1] = pq[i];
            }else{
               break;
            }            
         }   
         // insert the data 
         pq[i+1] = p;
         itemCount++;
      }
   }
}
struct node* removeData(){
   return pq[--itemCount]; 
}

int isEmpty(){
    if(itemCount == 0)
    	return 1;
    else
       return 0;
}

int isFull(){
   if(itemCount == MAX)
   	return 1;
   else
   return 0;
}

int size(){
   return itemCount;
}  

/*void minheapify(int i,int hs,struct node *heap[])
{	if(i>=hs)
		return;
	int l,max,r,j=i,t;	
		while(j<hs)
		{
		 l=(2*j)+1;
		r=(2*j)+2;
			max=j;
			if(l<hs && heap[l].cost<heap[max].cost)
			     max= l;
			if(r<hs && heap[r].cost<heap[max].cost) 
			   max=r;
		if(max!=j)
		{  
		    struct node tmp=heap[j];
			heap[j]=heap[max];
			heap[max]=tmp; 
		}	      
		else
		break; 
	    }
}
struct node *extractmin(struct node *heap[],int *n)
{	if((*n)<=0)
		return 0;
	struct node *max=heap[0];
	(*n)-=1;
	heap[0]=heap[*n];
	minheapify(0,*n,heap);
	return max;	
}
void increaseval(struct node q[],int i,int val,int pr)
{	int tmp;
	if(val<q[i].data)
		{
		printf("Cannot be inserted");  return;
	    }
	q[i].data=val;
	q[i].priority=pr;
	while(i>0 && q[i/2].priority<q[i].priority)
	{    tmp=q[i].data; q[i].data=q[i/2].data; q[i/2].data=tmp;
		tmp=q[i].priority; q[i].priority=q[i/2].priority; q[i/2].priority=tmp;
			i=i/2; 
	}
}
void enq(struct node *q[],struct node *n,int *n)
{		if((*n)==99)
			printf("Overflow");
		(*n)+=1;
		q[*n-1].cost=-99999;
		
		increaseval(q,(*n)-1,data,p);	
}*/
int check(struct node *i,struct node *f)
{
	int i,j,c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			{
				if(i->mat[i][j]!=f->mat[i][j])
					c++;
			}
	}
	return c;
}
int xm[4]={0,-1,0,1};
int ym[4]={-1,0,1,0};
int newnode(struct node *t,struct node *f,int x,int y,int lev)
{
	struct node *n=(struct node *)malloc(sizeof(Struct node));
	n->x=x;
	n->y=y;
	n->par=t;
	n->next=NULL;
	int i,j,c;
	n->mat[n->x][n->y]=0;
	for(i=0;i<n;i++)
	{
	for(j=0;j<j++)
	{
		if(i==t->x && j==t->y)
			n->mat[i][j]=t->mat[t->x][t->y];
		else
			n->mat[i][j]=t->mat[i][j];
	}
	}
	c=check=(n,f);
	n->cost=lev+c;
} 
	
void print(int mat[][3])
{
  int i,j;
  for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			{
				printf("%d",mat[i][j]);
			}
		printf("\n");
	}
}
void pzzle(struct node *t,struct node *f,int lev)
{
	int c,i,j,m,n;
	while(1)
	{
	c=check(t,f);
	if(c==0)
		{
			print(t->mat);
			return;
		}
	int levc=lev+1;
	for(i=0;i<4;i++)
		{
			m=t->x+xm[i];
			n=t->y+ym[i];
			if(t->x>=0 && t->x<n && t->y>=0 && t->y<n)
				{
					struct node *c=newnode(t,f,m,n,levc);
					int ch=check(c,f);
					if(c==0)
					{
                       while(c!=-1)
					{
					   print(c->mat);
					   c=c->par;
					}
					return;
					}
					insert(c);
				}
		}
	struct node *e=removeData();
	t=e;
	}
}	
int main()
{
    // Initial configuration
    // Value 0 is used for empty space
    struct node *i=(struct node*)malloc(sizeof(struct node));
	struct node *f=(struct node*)malloc(sizeof(struct node));
	i->par=-1;
	i->next=NULL;i->cost=0;
	f->par=-1;
	f->next=NULL;f->cost=0;
    i->mat[3][3]=
    {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };
 
    // Solvable Final configuration
    // Value 0 is used for empty space
    f->mat[3][3] =
    {
        {1, 2, 3},
        {5, 8, 6},
        {0, 7, 4}
    };
 
    // Blank tile coordinates in initial
    // configuration
    i->x = 1, i->y = 2;
    f->x=2,f->y=0;
    pzzle(i,f,0);
 
    return 0;
}
