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

#define maxN 3005

int N,M;
vector<int> adj[maxN];
int close[maxN];
bool removed[maxN];
bool visited[maxN];

void dfs(int n){
	visited[n]=true;
	for(int a:adj[n]) if(visited[a]==false){
		dfs(a);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("closing.in");
	ofstream cout("closing.out");
	cin>>N>>M;
	int u,v;
	for(int i=0;i<M;i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		cin>>close[i];
		close[i]--;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[j]=removed[j];
		}
		int groups=0;
		for(int j=0;j<N;j++){
			if(!visited[j]){
				dfs(j);
				groups++;
			}
		}
		removed[close[i]]=true;
		if(groups>1){
			cout<<"NO"<<'\n';
		}else{
			cout<<"YES"<<'\n';
		}
	}


    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/