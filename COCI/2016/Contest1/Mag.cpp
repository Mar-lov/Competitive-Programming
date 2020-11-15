/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pi;
 
#define maxN 1000005
#define INF 2000000000
 
long long N;
vector<long long> adj[maxN];
long long magic[maxN];
long long dp1[maxN];
long long f1[maxN];
long long dp2[maxN];
long long f2[maxN];
long long tmv=INF;
long long top=1;
long long bottom=1;
 
void na(long long t,long long b){
	if(t*bottom<top*b){
		top=t;
		bottom=b;
	}
}
 
 
void dfsbu(long long n,long long p){
 
	for(long long i:adj[n]) if(i!=p){
		dfsbu(i,n);
	}
 
	if(magic[n]>2) return;
 
	for(long long i:adj[n]) if(i!=p){
		if(magic[i]==1){
			if(dp1[i]>=dp1[n]){
				dp2[n]=dp1[n];
				f2[n]=f1[n];
				dp1[n]=dp1[i]+1;
				f1[n]=i;
			}else if(dp1[i]>=dp2[n]){
				dp2[n]=dp1[i]+1;
				f2[n]=i;
			}
		}
	}
}
 
void dfsud(long long n,long long p){
	
	if(magic[n]<3&&magic[p]==1){
		if(dp1[p]>=dp1[n]&&f1[p]!=n){
			dp2[n]=dp1[n];
			f2[n]=f1[n];
			dp1[n]=dp1[p]+1;
			f1[n]=p;
		}else if(dp2[p]>=dp1[n]&&f2[p]!=n){
			dp2[n]=dp1[n];
			f2[n]=f1[n];
			dp1[n]=dp2[p]+1;
			f1[n]=p;
		}else if(dp1[p]>=dp2[n]&&f1[p]!=n){
			dp2[n]=dp1[p]+1;
			f2[n]=p;
		}else if(dp2[p]>=dp2[n]&&f2[p]!=n){
			dp2[n]=dp2[p]+1;
			f2[n]=p;
		}
	}
	for(long long i:adj[n]) if(i!=p){
		dfsud(i,n);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	long long u,v;
	for(long long i=0;i<N-1;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(long long i=0;i<N;i++){
		cin>>magic[i];
		tmv=min(tmv,magic[i]);
		f1[i]=-1;
		f2[i]=-1;
		dp1[i]=0;
		dp2[i]=0;
		//if(magic[i]==1) dp1[i]=1;
	}
	if(tmv>1){
		cout<<tmv<<"/"<<1<<'\n';
		return 0;
	}
	dfsbu(0,-1);
	dfsud(0,-1);
    for(long long i=0;i<N;i++){
		if(magic[i]==2&&dp1[i]==dp2[i]){
			na(2,(dp1[i]+dp2[i]+1));
		}else if(magic[i]==1){
			na(1,(dp1[i]+dp2[i]+1));
		}
	}

		cout<<top<<"/"<<bottom<<'\n';

	return 0;
}
 
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/