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

#define maxC 2005

int T;
int p[maxC];
int r[maxC];

int findP(int n){
	if(p[n]==n) return n;
	int cp=findP(p[n]);
	p[n]=cp;
	return cp;
}

bool combine(int a,int b){
	int p1=findP(a);
	int p2=findP(b);
	if(p1==p2) return false;
	if(r[p1]<r[p2]) swap(p1,p2);
	p[p2]=p1;
	r[p1]=max(r[p1],r[p2]+1);
	return true;
}
vector< pi > adj[maxC];
int dfs(int n,int p){
	int sum=1;
	for(int i=0;i<adj[n].size();i++) if(adj[n][i].first!=p){
		sum+=dfs(adj[n][i].first,n)+adj[n][i].second;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		int M,C;
		cin>>M>>C;
		vector< pair<int,pi > > arr;
		int u,v,d;
		for(int i=0;i<C;i++){
			for(int j=i+1;j<C;j++){
				cin>>u>>v>>d;
				arr.push_back(make_pair(d,make_pair(u,v)));
			}
		}
		sort(arr.begin(),arr.end());
		for(int i=0;i<C;i++){
			p[i]=i;
			r[i]=1;
			adj[i].clear();
		}
		for(int i=0;i<arr.size();i++){
			u=arr[i].second.first;
			v=arr[i].second.second;
			d=arr[i].first;
			if(combine(u,v)){
				adj[u].push_back(make_pair(v,d));
				adj[v].push_back(make_pair(u,d));
			}
		}
		int minm=dfs(0,0);
		if(minm<=M) cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';

	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/