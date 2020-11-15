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

#define maxN 200005

int N,M;
vector<int> adj[maxN];
int p[maxN];
int pc[maxN];
queue<int> q;

int findP(int n){
	if(n==p[n]) return n;
	int cp=findP(p[n]);
	p[n]=cp;
	return cp;
}

void combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1!=p2){
		if(adj[p1].size()<adj[p2].size()) swap(p1,p2);
		adj[p1].insert(adj[p1].end(),adj[p2].begin(),adj[p2].end());
		p[p2]=p1;
	}
	if(adj[p1].size()>1) q.push(p1);
}


int main() {
	ifstream cin("fcolor.in");
	ofstream cout("fcolor.out");
	cin>>N>>M;
	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}

	for(int i=0;i<=N;i++){
		p[i]=i;
		if(adj[i].size()>1) q.push(i);
	}

	while(!q.empty()){
		int c=q.front();
		c=findP(c);
		if(adj[c].size()<=1){
			q.pop();
			continue;
		}
		int nv=adj[c].back();
		adj[c].pop_back();
		combine(nv,adj[c].back());
	}
	int cc=0;
	for(int i=1;i<=N;i++){
		int cv=findP(i);
		if(pc[cv]==0){
			cc++;
			pc[cv]=cc;
		}
		cout<<pc[cv]<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/