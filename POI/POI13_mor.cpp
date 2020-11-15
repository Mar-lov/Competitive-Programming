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
 
#define maxN 5005
const short INF = 31111;
 
int N,M,K;
vector<int> adj[maxN];
//from u to v min even and min odd
short dist[maxN][maxN][2];
 
void bfs(int p){
	queue< pair<int,int> > q;
	q.push(make_pair(p,0));
	while(!q.empty()){
		int cn=q.front().first;
		int cd=q.front().second;
		q.pop();
		for(int i=0;i<adj[cn].size();i++){
			int nn=adj[cn][i];
			if(dist[p][nn][(cd+1)%2]>cd+1){
				dist[p][nn][(cd+1)%2]=cd+1;
				q.push(make_pair(nn,cd+1));
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<maxN;i++){
		for(int j=0;j<maxN;j++){
			dist[i][j][0]=INF;
			dist[i][j][1]=INF;
		}
	}
	cin>>N>>M>>K;
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		u--;
		v--;
		dist[u][u][0]=0;
		dist[v][v][0]=0;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		bfs(i);
	}
	int a,b,d;
	for(int i=0;i<K;i++){
		cin>>a>>b>>d;
		a--;
		b--;
		if(dist[a][b][d%2]!=INF&&dist[a][b][d%2]<=d){
			cout<<"TAK"<<'\n';
		}else{
			cout<<"NIE"<<"\n";
		}
	}
 
 
    return 0;
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/