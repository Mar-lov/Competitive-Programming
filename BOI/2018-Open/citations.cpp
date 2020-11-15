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

long long N;
long long rt[maxN];
vector<long long> adj[maxN];
long long strt[maxN];
long long cis[maxN];
long long result=0;

void dfs1(long long p){
	for(long long i=0;i<adj[p].size();i++){
		dfs1(adj[p][i]);
		strt[p]+=strt[adj[p][i]];
		cis[p]+=cis[adj[p][i]];
	}
	strt[p]+=rt[p];
	cis[p]++;
}

bool cmp(long long a,long long b){
	return strt[a]*cis[b]<strt[b]*cis[a];
}

long long tob=0;
long long trt=0;
void dfs2(long long p){
	tob++;
	sort(adj[p].begin(),adj[p].end(),cmp);
	for(long long i=0;i<adj[p].size();i++){
		dfs2(adj[p][i]);
	}
	trt+=rt[p];
	result+=tob+trt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>rt[i];
		long long m;
		cin>>m;
		while(m--){
			long long templ;
			cin>>templ;
			templ--;
			adj[i].push_back(templ);
		}
	}
	dfs1(0);
    dfs2(0);
	cout<<result<<'\n';
	return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/