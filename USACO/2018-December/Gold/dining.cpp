/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 50005
#define INF (1<<30)

int N,M,K;
vector<pi> adj[maxN];
pi hb[maxN];
bool canDine[maxN];

int dist[maxN];
bool visited[maxN];
void dijkstras(int s){
	priority_queue<pi,vector<pi>,greater<pi> >pq;
	dist[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int cd=pq.top().first;
		int cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		visited[cn]=true;
		for(int i=0;i<adj[cn].size();i++){
			int ew=adj[cn][i].first;
			int tn=adj[cn][i].second;
			if(cd+ew<dist[tn]){
				dist[tn]=cd+ew;
					pq.push(make_pair(dist[tn],tn));
			}
		}
	}
}

void bfs(int n,int yv){
	queue<pi> q;
	q.push(make_pair(dist[n],n));
	canDine[n]=true;
	while(!q.empty()){
		int cd=q.front().first;
		int cn=q.front().second;
		q.pop();
		for(int i=0;i<adj[cn].size();i++){
			int ew=adj[cn][i].first;
			int tn=adj[cn][i].second;
			if((cd+ew)-dist[tn]<=yv){
				canDine[tn]=true;
				q.push(make_pair(cd+ew,tn));
			}
		}
	}
}

int main() {
	ifstream cin("dining.in");
	ofstream cout("dining.out");
	cin>>N>>M>>K;
	int u,v,w;
	for(int i=0;i<M;i++){
		cin>>u>>v>>w;
		u--;v--;
		adj[u].push_back(make_pair(w,v));
		adj[v].push_back(make_pair(w,u));
	}
	int b,y;
	for(int i=0;i<K;i++){
		cin>>b>>y;
		b--;
		hb[i]=make_pair(y,b);
	}
	sort(hb,hb+K);
	reverse(hb,hb+K);
	for(int i=0;i<N;i++){
		sort(adj[i].begin(),adj[i].end());
	}

	fill(dist,dist+N,INF);
	dijkstras(N-1);

	for(int i=0;i<K;i++){
	bfs(hb[i].second,hb[i].first);	
	}
	for(int i=0;i<N-1;i++){
		cout<<(canDine[i]?"1":"0")<<'\n';
	}
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/