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

int N,K;
vector<int> adj[100001];
int disttoLeaf[100001];
bool visited[100001];
int answer=0;

void dfs(int k){
	visited[k]=true;
	if(adj[k].size()==1&&visited[adj[k][0]]==true){
		disttoLeaf[k]=0;
	}else{
		for(int i=0;i<adj[k].size();i++){
			if(visited[adj[k][i]]==false){
				dfs(adj[k][i]);
				disttoLeaf[k]=min(disttoLeaf[k],disttoLeaf[adj[k][i]]+1);
			}
		}
	}
}


void bfs(int r){
	queue<pi> q;
	q.push(make_pair(r,0));
	visited[r]=true;
	while(!q.empty()){
		int cn=q.front().first;
		int cd=q.front().second;
		q.pop();
		if(adj[cn].size()==1&&visited[adj[cn][0]]==true){
			answer++;
		}else{
			bool hf1=false;
			bool ntf1=false;
			if(disttoLeaf[cn]<=cd){
				ntf1=true;
			}
		for(int i=0;i<adj[cn].size()&&!(ntf1&&hf1);i++){
			if(visited[adj[cn][i]]==false){
				hf1=true;
				visited[adj[cn][i]]=true;
				q.push(make_pair(adj[cn][i],cd+1));
			}
		}
		}
	}

}

int main() {
	ifstream cin("atlarge.in");
	ofstream cout("atlarge.out");
	cin>>N>>K;
	K--;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(disttoLeaf,disttoLeaf+100001,(1<<30));
	dfs(K);
	fill(visited,visited+100001,false);
	bfs(K);
	cout<<answer<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/