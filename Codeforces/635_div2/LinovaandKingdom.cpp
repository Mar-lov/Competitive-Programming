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
vector<int> adj[200005];
bool bfsv[200005];
bool dfsv[200005];
pair<int,int> sts[200005];
int dp[200005];

int findsts(int n){
	dfsv[n]=true;
	sts[n].second*=-1;
	for(int i=0;i<adj[n].size();i++){
		if(dfsv[adj[n][i]]==false){
		sts[n].first+=findsts(adj[n][i]);
		}
	}
	return sts[n].first+1;
}

int main() {
	cin>>N>>K;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(0);
	sts[0].second=0;
	while(!q.empty()){
		int cl=q.front();
		q.pop();
		bfsv[cl]=true;
		for(int i=0;i<adj[cl].size();i++){
			if(bfsv[adj[cl][i]]==false){
				q.push(adj[cl][i]);
				sts[adj[cl][i]].second=sts[cl].second+1;
			}
		}
	}
	findsts(0);
	sort(sts,sts+N);
	reverse(sts,sts+N);

	dp[0]=0;
	for(int i=1;i<=N;i++){
		dp[i]=dp[i-1]+sts[i-1].first+sts[i-1].second;
		//cout<<i<<" "<<dp[i]<<"\n";
	}
	cout<<dp[N-K]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/