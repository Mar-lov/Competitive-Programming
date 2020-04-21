/*
code by @marlov       
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

#define maxN 200005

int N,M;
vector<int> adj[maxN];
int co[maxN];
bool addedIn[maxN];
int ans[maxN];

int p[maxN];
int r[maxN];
int tsg;

int findP(int n){
	if(n==p[n]) return n;
	return findP(p[n]);
}

void merge(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2){
	if(r[p1]<r[p2]) swap(p1,p2);
	p[p2]=p1;
	r[p1]=max(r[p1],r[p2]+1);
	tsg--;
	}
}

int main() {
	ifstream cin("closing.in");
	ofstream cout("closing.out");
	cin>>N>>M;
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		cin>>co[i];
	}
	tsg=N;
	for(int i=0;i<=N;i++){
		p[i]=i;
		r[i]=i;
	}
	for(int i=N-1;i>=0;i--){
		int cv=co[i];
		addedIn[cv]=true;
		for(int j=0;j<adj[cv].size();j++){
			if(addedIn[adj[cv][j]]==true){
				merge(cv,adj[cv][j]);
			}
		}
		if(tsg==i+1){
			ans[i]=1;
		}
	}	
	for(int i=0;i<N;i++){
		cout<<(ans[i]==1?"YES":"NO")<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/