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

#define maxN 50002

int N,K;
vector<int> adj[maxN];
int lev[maxN];
int bl[maxN][30];
int psum[maxN];
int result=0;

void dfs1(int p){
	for(int i=0;i<adj[p].size();i++){
		if(lev[adj[p][i]]==0){
			lev[adj[p][i]]=lev[p]+1;
			bl[adj[p][i]][0]=p;
			dfs1(adj[p][i]);
		}
	}
}

int lca(int u,int v){
	if(lev[u]<lev[v]){
		swap(u,v);
	}
	int dt=abs(lev[u]-lev[v]);
	for(int i=0;i<30;i++){
		if(dt&(1<<i)) u=bl[u][i];
	}
	if(u==v) return v;

	for(int i=29;i>=0;i--){
		if(bl[u][i]!=bl[v][i]){
			u=bl[u][i];
			v=bl[v][i];
		}
	}
	return bl[v][0];
}

//p is for parent
int dfs2(int n,int p){
	int sum=0;
	for(int i=0;i<adj[n].size();i++){
		if(adj[n][i]!=p){
			sum+=dfs2(adj[n][i],n);
		}
	}
	result=max(result,psum[n]+sum);
	return psum[n]+sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("maxflow.in");
	ofstream cout("maxflow.out");
	cin>>N>>K;
	int a,b;
	for(int i=0;i<N-1;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	lev[1]=1;
	bl[1][0]=1;

	dfs1(1);

	for(int j=1;j<30;j++){
		for(int i=1;i<=N;i++){
			bl[i][j]=bl[bl[i][j-1]][j-1];
		}
	}

	int u,v;
	for(int i=0;i<K;i++){
		cin>>u>>v;
		int cn=lca(u,v);
		psum[u]++;
		psum[v]++;
		psum[cn]--;
		if(bl[cn][0]!=cn) psum[bl[cn][0]]--;
	}

	dfs2(1,0);

	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/