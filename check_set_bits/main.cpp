#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,n;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    int c=1;
	    while(n){
	        c=n&1;
	        if(c==0){
	            printf("NO\n");
	            break;

	        }
	        n=n>>1;
	    }
	    if(c==1)
	    printf("YES\n");
	}
	return 0;
}

