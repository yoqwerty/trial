#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	//code
	ll t;
	scanf("%d",&t);
	ll i,n,res;
	while(t--){
	    res=0;
	   scanf("%lld",&n);
	   ll a[n];
	   ll c[3];
	   memset(c,0,3*sizeof(c[0]));
	   for(i=0;i<n;i++){
	       scanf("%lld",&a[i]);
	       c[a[i]%3]++;
	   }
	   res+=c[0]*(c[0]-1)/2;
	   res+=c[0]*c[1]*c[2];
	   res+=c[1]*c[2];
	   res+=c[0]*(c[0]-1)*(c[0]-2)/6;
	   res+=c[1]*(c[1]-1)*(c[1]-2)/6;
	   res+=c[2]*(c[2]-1)*(c[2]-2)/6;
	   printf("%d\n",res);
	}
	return 0;
}

