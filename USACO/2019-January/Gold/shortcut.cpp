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

#define INF 2000000000
#define maxN 10005

int N,M,T;
int cowat[maxN];
vector<pi> adj[maxN];
int dist[maxN];
bool visited[maxN];
int path[maxN];
ll md=0;

void dijkstras(){
	priority_queue< pi , vector<pi> , greater<pi> > pq;
	pq.push(make_pair(0,0));
	dist[0]=0;
	path[0]=0;
	while(!pq.empty()){
		int cd=pq.top().first;int cn=pq.top().second;pq.pop();
		if(visited[cn]==true) continue;
		visited[cn]=true;
		for(int i=0;i<adj[cn].size();i++){
			int tn=adj[cn][i].first; int ed=adj[cn][i].second;
			if(dist[tn]>cd+ed||(dist[tn]==cd+ed&&path[tn]>cn)){
				path[tn]=cn;
				dist[tn]=cd+ed;
				pq.push(make_pair(dist[tn],tn));
			}
		}
	}
}

vector<int> pl[maxN];

int dfs(int n,int p){
	ll tv=cowat[n];
	for(int i=0;i<pl[n].size();i++){
		if(pl[n][i]!=p) tv+=dfs(pl[n][i],n);
	}
	md=max(md,((ll)dist[n]-(ll)T)*tv);
	return tv;
}

int main() {
	ifstream cin("shortcut.in");
	ofstream cout("shortcut.out");
	cin>>N>>M>>T;
	for(int i=0;i<N;i++){
		cin>>cowat[i];
	}
	fill(dist,dist+N,INF);
	fill(path,path+N,maxN);
	int u,v,d;
	for(int i=0;i<M;i++){
		cin>>u>>v>>d;
		u--;v--;
		adj[u].push_back(make_pair(v,d));
		adj[v].push_back(make_pair(u,d));
	}
	dijkstras();

	for(int i=1;i<N;i++){
		pl[path[i]].push_back(i);
	}

	dfs(0,-1);
	cout<<md<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/