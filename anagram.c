#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
     ll t,i,j;
     string s,q;
	scanf("%lld",&t);
	while(t--){
	    int f=0;
	    cin>>s>>q;
	    //scanf("%s",&s);
	    //scanf("%s",&q);
	    j=s.size();ll h[j];memset(h,0,j*sizeof(h[0]));
	    if(s.size()!=q.size()){
	        printf("NO\n");
	        continue;
	    }
	    for(i=0;i<j;i++){
	        h[s[i]]=1;
	    }
	    for(i=0;i<j;i++){
	        if(h[q[i]]!=1)
	        {   printf("NO\n");
	            f=1;
	            break;
	        }
	    }
	    if(f==0)printf("YES\n");
	}
	return 0;
}
