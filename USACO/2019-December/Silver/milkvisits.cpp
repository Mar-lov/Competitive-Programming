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

#define maxN 100005

int N,M;
string s;
vector<int> adj[maxN];
bool visited[maxN];

//UDFS
int p[maxN];
int r[maxN];

int findP(int n){
	if(n==p[n]) return n;
	int pv=findP(p[n]);
	p[n]=pv;
	return pv;
}

void combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(r[p1]<r[p2]) swap(p1,p2);
	p[p2]=p1;
	r[p1]=max(r[p1],r[p2]+1);
}

void dfs(int n){
	visited[n]=true;
	for(int a:adj[n]) if(!visited[a]&&s[n]==s[a]){
		combine(n,a);
		dfs(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");
	cin>>N>>M;
	cin>>s;
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		p[i]=i;
		r[i]=1;
	}
	for(int i=0;i<N;i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	char c;
	for(int i=0;i<M;i++){
		cin>>u>>v>>c;
		u--;v--;
		if(findP(u)!=findP(v)){
			cout<<1;
		}else if(s[u]==c&&findP(u)==findP(v)){
			cout<<1;	
		}else{
			cout<<0;
		}
	}
	cout<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/