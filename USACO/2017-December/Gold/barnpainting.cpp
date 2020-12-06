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
typedef pair<long long,long long> pi;

#define maxN 100005
#define MOD 1000000007

long long N,K;
vector<long long> adj[maxN];
long long color[maxN];
long long dp[maxN][3];

void dfs(long long n,long long p){
	for(long long a:adj[n]) if(a!=p){
		dfs(a,n);
	}
	//leaves
	if(adj[n].size()==1&&adj[n].front()==p&&color[n]==-1){
		dp[n][0]=1;
		dp[n][1]=1;
		dp[n][2]=1;
		return;
	}
	for(long long c=0;c<3;c++){
		if(color[n]==-1||c==color[n]){
			dp[n][c]=1;
		}
		for(long long a:adj[n]) if(a!=p){
			long long cs=0;
			for(long long i=0;i<3;i++) if(i!=c){
				cs+=dp[a][i];
			}
			dp[n][c]*=cs;
			dp[n][c]%=MOD;
			//cout<<a<<" not "<<c<<" has "<<cs<<" creates:"<<dp[n][c]<<'\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("barnpainting.in");
	ofstream cout("barnpainting.out");
	cin>>N>>K;
	long long u,v;
	for(long long i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(color,color+N,-1);
	long long b,c;
	for(long long i=0;i<K;i++){
		cin>>b>>c;
		b--;
		c--;
		color[b]=c;
	}
	dfs(0,0);
	cout<<(dp[0][0]+dp[0][1]+dp[0][2])%MOD<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/