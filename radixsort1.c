# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void stablesort(char **input,int n,int index,int k)
{
	int i,count[100]={0};
	char output[n][k];
	int ch;
	for(i=0;i<n;i++){
		ch=input[i][index]-32;
		count[ch]++;
	}
	for(i=1;i<=99;i++)
		count[i]+=count[i-1];
	for(i=n-1;i>=0;i--){
		ch=input[i][index]-32;
		strcpy(output[count[ch]-1],input[i]);
		count[ch]--;
	}
	for(i=0;i<n;i++)
		strcpy(input[i],output[i]);
	/*for(i=0;i<n;i++)
    {
      printf("index=%d %s\n",index,input[i]);
    }*/
}

void radix_sort(char **input,int n,int k)
{
	int i;
	for(i=k-1;i>=0;i--)
		stablesort(input,n,i,k);
}	

int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
	//scanf("%s",input[i]);
      input[i][k]='\0';
      //printf("\n%s\n",input[i]);
    }
  radix_sort(input,n,k);
  for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
  
  return 0;
}



