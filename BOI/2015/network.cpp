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

#define maxN 500005

int N;
int tl=0;
int leaves[maxN];
int root=0;
vector<int> adj[maxN];
vector< pair<int,int> > edges;
vector< vector<int> > connect;
priority_queue< pair<int,int> > pq;

void findRoot(int n,int p){
	if(adj[n].size()==1){
		leaves[n]++;
	}
	bool wks=true;
	for(int i:adj[n]) if(i!=p){
		findRoot(i,n);
		if(leaves[i]>floor(tl/2)) wks=false; 
		leaves[n]+=leaves[i];
	}
	if(tl-leaves[n]>floor(tl/2)) wks=false;
	if(wks&&adj[n].size()>1) root=n;
}

void addL(int n,int p){
	if(adj[n].size()==1){
		connect.back().push_back(n);
		return;
	}
	for(int i:adj[n]) if(i!=p){
		addL(i,n);
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
		if(adj[i].size()==1) tl++;
	}
	findRoot(0,-1);
	for(int i:adj[root]){
		int ci=connect.size();
		connect.push_back(vector<int>(0));
		addL(i,root);
		pq.push(make_pair(connect[ci].size()-1,ci));
	}
	while(pq.size()>1){
		int fi=pq.top().second; 
		int fl=pq.top().first; pq.pop();
		int sl=pq.top().first;
		int si=pq.top().second;pq.pop();
		edges.push_back(make_pair(connect[fi][fl],connect[si][sl]));
		if(fl>0) pq.push(make_pair(fl-1,fi));
		if(sl>0) pq.push(make_pair(sl-1,si));
	}
	if(pq.size()==1){
		edges.push_back(make_pair(connect[pq.top().second].front(),root));
	}
		cout<<edges.size()<<'\n';
	for(int i=0;i<(int)edges.size();i++){
		cout<<edges[i].first+1<<" "<<edges[i].second+1<<'\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/