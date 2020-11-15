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

#define maxN 50005

long long N,M;
vector< pair<long long,long long> > edges;
vector<long long> adj[maxN];
multiset<long long> open[maxN];
multiset<long long> close[maxN];
long long lev[maxN];
long long bl[maxN][17];
unordered_map< long long, unordered_map< long long, long long > > result;

void dfsbl(long long n,long long p){
	bl[n][0]=p;
	for(long long i=0;i<adj[n].size();i++){
		if(adj[n][i]!=p){
			lev[adj[n][i]]=lev[n]+1;
			dfsbl(adj[n][i],n);
		}
	}
}

long long LCA(long long u,long long v){
	if(lev[u]<lev[v]) swap(u,v);
	long long dt=lev[u]-lev[v];
	for(long long i=0;i<17;i++){
		if(dt&(1<<i)) u=bl[u][i];
	}
	if(u==v) return u;
	for(long long i=16;i>=0;i--){
		while(bl[u][i]!=bl[v][i]){
			u=bl[u][i];
			v=bl[v][i];
		}
	}
	return bl[u][0];
}

void solve(long long n,long long p){
	long long big_index=n;
	for(long long i=0;i<adj[n].size();i++) if(adj[n][i]!=p){
		solve(adj[n][i],n);
		if(open[adj[n][i]].size()>open[big_index].size()){
			big_index=adj[n][i];
		}
	}
	swap(open[n],open[big_index]);
	for(long long i:adj[n]) if(i!=p){
		open[n].insert(open[i].begin(),open[i].end());
	}
	for(long long value: close[n]){
		open[n].erase(open[n].find(value));
	}
	int cn=n;
	if(p<n) swap(p,n);
	if(open[cn].size()==0){
		result[n][p]=-1;
	}else{
		result[n][p]=*open[cn].begin();
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("disrupt.in");
	ofstream cout("disrupt.out");
	cin>>N>>M;
	long long u,v;
	for(long long i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		if(v<u) swap(u,v);
		edges.push_back(make_pair(u,v));
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	//setup binary lifting
	lev[0]=0;
	dfsbl(0,0);
	bl[0][0]=0;
	for(long long i=1;i<17;i++){
		for(long long j=0;j<N;j++){
			bl[j][i]=bl[bl[j][i-1]][i-1];
		}
	}
	long long p,q,r;
	for(long long i=0;i<M;i++){
		cin>>p>>q>>r;
		p--;
		q--;
		open[p].insert(r);
		open[q].insert(r);
		close[LCA(p,q)].insert(r);
		close[LCA(p,q)].insert(r);
	}

	solve(0,-1);
    
	for(long long i=0;i<N-1;i++){
		cout<<result[edges[i].first][edges[i].second]<<'\n';
	}

	return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/