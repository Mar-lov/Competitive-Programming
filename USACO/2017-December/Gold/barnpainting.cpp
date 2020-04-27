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

#define MOD 1000000007
#define maxV 100005

int N,K;
vector<int> adj[maxV];
int color[maxV];
ll dp[maxV][3];

ll solve(int cn,int cc,int pn,int pc){
	if(cc==pc||(color[cn]>=0&&cc!=color[cn])) return 0;
	if(dp[cn][cc]>=0) return dp[cn][cc];
	dp[cn][cc]=1;
	for(int i=0;i<adj[cn].size();i++){
		if(adj[cn][i]==pn) continue; 
		ll canColor=0;
		for(int j=0;j<3;j++){
			canColor+=solve(adj[cn][i],j,cn,cc);
			canColor%=MOD;
		}	
		dp[cn][cc]*=canColor;
		dp[cn][cc]%=MOD;
	}
	return dp[cn][cc];
}

int main() {
	ifstream cin("barnpainting.in");
	ofstream cout("barnpainting.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		dp[i][0]=-1;
		dp[i][1]=-1;
		dp[i][2]=-1;
		color[i]=-1;
	}
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int b,c;
	for(int i=0;i<K;i++){
		cin>>b>>c;
		b--;
		c--;
		color[b]=c;
	}
	//use colors 1,2,3
	ll ans=solve(0,0,-1,-1)+solve(0,1,-1,-1)+solve(0,2,-1,-1);
	cout<<(ans%MOD)<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/