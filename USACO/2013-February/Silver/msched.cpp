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

#define maxN 10005

int N,M;
int T[maxN];
vector<int> adj[maxN];
int dp[maxN];
int result=0;

int dfs(int n){
	if(dp[n]!=0) return dp[n];
	for(int a:adj[n]){
		dp[n]=max(dp[n],dfs(a));
	}
	dp[n]+=T[n];
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("msched.in");
	ofstream cout("msched.out");
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>T[i];
	}
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		u--;v--;
		adj[u].push_back(v);
	}
	//fill(dp,dp+N,-1);
	for(int i=0;i<N;i++){
		dp[i]=dfs(i);
		result=max(dp[i],result);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/