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

#define maxN 100005
#define INF 1000000000

int N,M,T;
int S,E;
int K;
int spider[maxN];
vector<pi> adj[maxN];
int msd[maxN];
int dist[maxN];

void dijkstras(priority_queue<pi,vector< pi > ,greater<pi> > pq){
	while(!pq.empty()){
		int n=pq.top().second;
		int cd=pq.top().first;
		if(cd>dist[n]) continue;
		for(int i=0;i<adj[n].size();i++){
			 int nn=adj[n][i].first;
			 int nd=adj[n][i].second;
			 if(dist[n]+nd<dist[nn]){
				 dist[nn]=dist[n]+nd;
				 pq.push(make_pair(dist[nn],nn));
			 }
		}
	}
}
void dijkstrasP(int p,priority_queue<pi,vector< pi > ,greater<pi> > pq){
	while(!pq.empty()){
		int n=pq.top().second;
		int cd=pq.top().first;
		if(cd>dist[n]) continue;
		for(int i=0;i<adj[n].size();i++){
			 int nn=adj[n][i].first;
			 int nd=adj[n][i].second;
			 if(dist[n]+nd<dist[nn]&&msd[nn]>=p){
				 dist[nn]=dist[n]+nd;
				 pq.push(make_pair(dist[nn],nn));
			 }
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>T;
	int u,v,d;
	for(int i=0;i<M;i++){
		cin>>u>>v>>d;
		adj[u].push_back(make_pair(v,d));
		adj[v].push_back(make_pair(u,d));
	}
	cin>>S>>E;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>spider[i];
	}
	fill(dist,dist+N,INF);
	priority_queue<pi,vector< pi > ,greater<pi> > ccq;
	for(int i=0;i<K;i++){
		ccq.push(make_pair(0,spider[i]));
	}
	dijkstras(ccq);
	for(int i=0;i<N;i++){
		msd[i]=dist[i];
	}
	int a=0;
	int b=10000;
	priority_queue<pi,vector< pi > ,greater<pi> > pp;
	pp.push(make_pair(0,E));
	while(a<b){
		int mid=(a+b+1)/2;
		fill(dist,dist+N,INF);
		dijkstrasP(mid,pp);
		if(dist[S]!=INF){
			a=mid;
		}else{
			b=mid-1;
		}
	}
	cout<<a<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/