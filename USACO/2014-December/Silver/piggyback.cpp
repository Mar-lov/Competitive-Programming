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

ll B,E,P,N,M;
vector<ll> adj[40005];
ll dist[40005][3];
ll mind=1000000000000000;

void bfs(int start,int di){
	bool visited[N+1];
	for(int i=0;i<=N;i++){
		visited[i]=false;
	}

	queue<int> q;
	q.push(start);
	dist[start][di]=0;
	visited[start]=true;
	while(!q.empty()){
		int c=q.front();
		q.pop();
		for(int i=0;i<adj[c].size();i++){
			if(visited[adj[c][i]]==false){
				visited[adj[c][i]]=true;
				dist[adj[c][i]][di]=dist[c][di]+1;
				q.push(adj[c][i]);
			}
		}
	}
}

int main() {
	ifstream cin("piggyback.in");
	ofstream cout("piggyback.out");
	cin>>B>>E>>P>>N>>M;
	ll u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1,0);
	bfs(2,1);
	bfs(N,2);
	for(int i=1;i<=N;i++){
		mind=min(mind,dist[i][0]*B+dist[i][1]*E+dist[i][2]*P);
	}
	cout<<mind<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/