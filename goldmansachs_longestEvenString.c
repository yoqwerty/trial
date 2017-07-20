#include <bits/stdc++.h>

using namespace std;

int main()
{   string a;
    //char a[100];
   // fgets(a,sizeof(a),stdin);
    getline(cin,a);
   //cin >>a;
    int j=0,i=0,c,e,b,g=0,h;
    while(a[i]!='\0'){
            c=0;
            j=i;
    //printf("%c here",a[3]);
    while(1){
            if(a[i]==' '||a[i]=='\0')
            break;
       // printf("%c %d",a[i],i);
        c++;
        printf("count increases for %d count %c\n",c,a[i]);
        i++;
    }
   // if(a[i]=='\0')c--;
    printf("count %d ",c);
    if(c>g && c%2==0){
        g=c;
        b=j;
        e=i-1;
    }
    if(a[i]=='\0')break;
    i++;
   // printf("%d i",i);

    }
   // printf("%d %d",b,e);
    for(h=b;h<=e;h++)
       printf("%c",a[h]);
    return 0;
}

