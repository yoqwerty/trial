#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll t,i,j,k,n,g,q,in,head,tail;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&g);
		while(g--){
			head=0;tail=0;
			scanf("%lld %lld %lld",&in,&n,&q);
			if(n%2==0){
				 head=n/2;
				 tail=n/2;

			}
			if(n%2!=0){
				if(in==1){
					tail=(n/2)+1;
					head=n/2;
				}
				else{
					tail=n/2;
					head=(n/2)+1;
				}
			}
			if(q==1)
			printf("%lld\n",head);
			else printf("%lld\n",tail);
		}
	}
}






