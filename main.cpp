#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pn printf("\n")
int main()
 {
	ll t,i,j,n;
	scanf("%lld",&t);
	while(t--){
	    scanf("%lld",&n);
	    ll a[n],b[n],c[n],m[100000];
	    memset(m,0,100000*sizeof(m[0]));
	    /*for(i=0;i<100000;i++){
            m[i]=0;
	    }*/
	    for(i=0;i<n;i++){
	        scanf("%lld",&a[i]);
	        c[i]=a[i];
	    }
	    for(i=0;i<n;i++){
	        scanf("%lld",&b[i]);
	    }
	    sort(b,b+n);
	    sort(c,c+n);
	    /*for(i=0;i<n;i++){
            printf("%lld ",b[i]);
	    }
	    pn;
	    for(i=0;i<n;i++){
            printf("%lld ",c[i]);
	    }*/
	    int in=0;

	    for(j=0;j<n;j++){
	        if(j!=0){
	            m[c[j]]=m[c[j-1]];
	           // printf("%lld %lld \n",m[c[j]],m[c[j-1]]);
	            in=i;
	        }
	        for(i=in;i<n;i++){

	            if(b[i]<=c[j]){
	                m[c[j]]++;
	               // printf("%lld %lld %lld %lld %lld\n",m[c[j]], c[j],j,b[i],i);
	            }
                else break;
            }
	    }
	    for(i=0;i<n;i++){
            if(i==n-1)
            printf("%lld",m[a[i]]);
            else
	        printf("%lld,",m[a[i]]);
	    }
	    printf("\n");
	}
	return 0;
}

