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

#define maxN 100005

int N;
int fat[maxN];
vector<int> adj[maxN];
int sts[maxN];
ll mind=(1LL<<58);

ll dfs(int n,int p,ll cs){
	int tl=0;
	if(adj[n].size()==0){
		 sts[n]=1;
		 return cs;
	}
	for(int i=0;i<adj[n].size();i++){
		if(adj[n][i]!=p){
			tl+=dfs(adj[n][i],n,cs+fat[adj[n][i]]);
			sts[n]+=sts[adj[n][i]];
		}
	}
	return tl;
}

void dfs2(int n,int p,ll val){
	mind=min(mind,val);
	
	for(int i=0;i<adj[n].size();i++){
		if(adj[n][i]!=p&&adj[adj[n][i]].size()>0){
			//cout<<val-(sts[adj[n][i]]*fat[adj[n][i]])+(4*(sts[1]-sts[adj[n][i]]))<<'\n';
			ll nv=val-((ll)sts[adj[n][i]]*(ll)fat[adj[n][i]])+((ll)3*((ll)sts[1]-(ll)sts[adj[n][i]]));
			dfs2(adj[n][i],n,nv);
		}
	}
}

int main() {
	ifstream cin("dirtraverse.in");
	ofstream cout("dirtraverse.out");
	cin>>N;
	string name;
	int m;
	for(int i=1;i<=N;i++){
		cin>>name>>m;
		fat[i]=name.length()+(m>0?1:0);
		int ct;
		for(int j=0;j<m;j++){
			cin>>ct;
			//what do we add?
			adj[i].push_back(ct);
		}
	}
	ll bessies=dfs(1,0,0);
	dfs2(1,0,bessies);
	cout<<mind<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/