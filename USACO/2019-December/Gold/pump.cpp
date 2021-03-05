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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxV 1005
#define INF 1000000009

struct pipe{
	int c,f;
};

int N,M;
pipe vals[maxV];
vector< pi > adj[maxV]; 
set<int> bottle;
int result=0;

bool visited[maxV];
int dist[maxV];
int dijkstra(int mf){
	priority_queue< pi , vector<pi> , greater<pi> > pq;
	fill(dist,dist+maxV,INF);
	fill(visited,visited+maxV,false);
	pq.push(make_pair(0,0));
	dist[0]=0;
	while(!pq.empty()){
		int cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		visited[cn]=true;
		for(pi a:adj[cn]){
			int nn=a.first;
			pipe cur=vals[a.second];
			if(cur.f<mf) continue;
			if(dist[nn]>dist[cn]+cur.c){
				dist[nn]=dist[cn]+cur.c;
				pq.push(make_pair(dist[nn],nn));
			}
		}
	}
	return dist[N-1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("pump.in");
	ofstream cout("pump.out");
	cin>>N>>M;
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v>>vals[i].c>>vals[i].f;
		u--;v--;
		adj[u].push_back(make_pair(v,i));
		adj[v].push_back(make_pair(u,i));
		bottle.insert(vals[i].f);
	}
	for(int f:bottle){
		//cout<<f<<" "<<dijkstra(f)<<'\n';
		result=max( result , (int)((double)1000000*f/(double)dijkstra(f)) );
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/