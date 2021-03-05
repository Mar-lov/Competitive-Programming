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
typedef pair<int,int> ii;

#define maxV 100005
#define maxB 17

int N,M;
int type[maxV];
vector<int> adj[maxV];
//current values at each node
set< ii > arr[maxV];
//removal values at a specific node
vector< ii > rm[maxV];
bool answer[maxV];

//start lca code
int bl[maxV][maxB];
int level[maxV];

void cg(int n,int p){
	level[n]=level[p]+1;
	bl[n][0]=p;
	for(int a:adj[n]) if(a!=p){
		cg(a,n);
	}
}

int lca(int a,int b){
	if(level[a]<level[b]) swap(a,b);
	int dl=level[a]-level[b];
	for(int i=maxB-1;i>=0;i--){
		if((1<<i)&dl) a=bl[a][i];
	}
	if(a==b) return a;
	for(int i=maxB-1;i>=0;i--){
		if(bl[a][i]!=bl[b][i]){
			a=bl[a][i];
			b=bl[b][i];
		}
	}
	return bl[a][0];
}
//end lca code

void dfs(int n,int p){
	//mergesmall to large
	int big_index=n;
	for(int a:adj[n]) if(a!=p){
		dfs(a,n);
		if(arr[a].size()>arr[big_index].size()) big_index=a;
	}
	swap(arr[n],arr[big_index]);
	for(int a:adj[n]) if(a!=p){
		for(ii nv:arr[a]){
			//nv.first!=type[a]||
			if(!answer[nv.second]) arr[n].insert(nv);
		}
	}

	//set all values that have same type to true and remove
	set<ii>::iterator fv=lower_bound(arr[n].begin(),arr[n].end(),make_pair(type[n],-1));
	while(fv!=arr[n].end()&&(*fv).first==type[n]){
		answer[(*fv).second]=true;
		fv++;
	}

	for(ii a:rm[n]){
		arr[n].erase(a);
	}

}


int main() {
	ifstream cin("milkvisits.in");
	ofstream cout("milkvisits.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	//Input
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>type[i];
	}
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//sets up the lca
	cg(0,0);
	for(int j=1;j<maxB;j++){
		for(int i=0;i<N;i++){
			bl[i][j]=bl[bl[i][j-1]][j-1];
		}
	}
	//reads in querys and adds to tree
	int A,B,C;
	for(int i=0;i<M;i++){
		cin>>A>>B>>C;
		A--;
		B--;
		//add to their nodes
		arr[A].insert(make_pair(C,i));
		arr[B].insert(make_pair(C,i));
		//makes lca removal value
		rm[lca(A,B)].push_back(make_pair(C,i));
	}
	//runs solution
	dfs(0,0);
	//outputs answer
	for(int i=0;i<M;i++){
		if(answer[i]) cout<<"1";
		else cout<<"0";
	}
	cout<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/