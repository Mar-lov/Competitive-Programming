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
typedef pair<long long,long long> pi;

#define maxN 100005

long long N;
vector<long long> adj[maxN];

long long dfs(long long n,long long p){
	long long days=0;
	while(adj[n].size()-(n==0?0:1)+1>pow(2,days)) days++;
	for(long long a:adj[n]) if(a!=p){
		days++;
		days+=dfs(a,n);
	}
	return days;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	long long u,v;
	for(long long i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	cout<<dfs(0,0)<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/