#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll t,i,n,diff,d;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ll a[n];
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		diff=1000000000;
		for(i=0;i<n-1;i++){
			d=a[i+1]-a[i];
			if(diff>d)
				diff=d;
		}
		printf("%lld\n",diff);
	}
}
