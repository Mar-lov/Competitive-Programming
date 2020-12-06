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

#define maxN 105
#define INF 15000
int N,M;
vector< pair<int, pair<int,int> > > adj[maxN];
unordered_set<int> btime[maxN];
unordered_set<int> etime[maxN];
int result=INF;
void bfs(){
	for(int n=0;n<N;n++){
		for(int i=0;i<adj[n].size();i++){
			int v=adj[n][i].first;
			int bc=adj[n][i].second.first;
			int ec=adj[n][i].second.second;
			for(int a:btime[n]){
				btime[v].insert(a+bc);
			}
			for(int a:etime[n]){
				etime[v].insert(a+ec);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("meeting.in");
	ofstream cout("meeting.out");
	cin>>N>>M;
	int u,v,b,e;
	for(int i=0;i<M;i++){
		cin>>u>>v>>b>>e;
		u--;
		v--;
		adj[u].push_back(make_pair(v,make_pair(b,e)));
	}
	btime[0].insert(0);
	etime[0].insert(0);
	bfs();

	for(int a:btime[N-1]){
		if(etime[N-1].find(a)!=etime[N-1].end()){
			result=min(result,a);
		}
	}

	if(result!=INF){
		cout<<result<<'\n';
	}else{
	cout<<"IMPOSSIBLE"<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/