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
typedef pair<int,int> pi;

#define maxN 1000005
#define INF 2000000000

int N;
vector<int> adj[maxN];
int magic[maxN];
int dp1[maxN];
int f1[maxN];
int dp2[maxN];
int f2[maxN];
int tmv=INF;
int top=1;
int bottom=1;

void dfsbu(int n,int p){

	for(int i:adj[n]) if(i!=p){
		dfsbu(i,n);
	}

	if(magic[n]>2) return;

	for(int i:adj[n]) if(i!=p){
		if(magic[i]==1){
			if(dp1[i]>=dp1[n]){
				dp2[n]=dp1[n];
				dp1[n]=dp1[i]+1;
				f1[n]=i;
			}else if(dp2[i]>=dp2[n]){
				dp2[n]=dp2[i]+1;
				f2[n]=i;
			}
		}
	}
}

void dfsud(int n,int p){
	
	if(magic[n]<3&&n!=0){
		if(dp1[p]>=dp1[n]&&f1[p]!=n){
			dp2[n]=dp1[n];
			dp1[n]=dp1[p]+1;
			f1[n]=p;
		}else if(dp2[p]>=dp2[n]&&f2[p]!=n){
			dp2[n]=dp2[p]+1;
			f2[n]=p;
		}
	}
	for(int i:adj[n]) if(i!=p){
		dfsud(i,n);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<N;i++){
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
    for(int i=0;i<N;i++){
		if(magic[i]>2) continue;
		if(top*(dp1[i]+dp2[i]+1)>bottom*magic[i]){
			top=magic[i];
			bottom=(dp1[i]+dp2[i]+1);
		}
	}
	if(top==2&&bottom%2==0){
		cout<<top/2<<"/"<<bottom/2<<'\n';
	}else{
		cout<<top<<"/"<<bottom<<'\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/