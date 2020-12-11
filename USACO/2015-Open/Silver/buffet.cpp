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

#define maxN 1004

long long N,E;
pi val[maxN];
vector<long long> adj[maxN];
long long dist[maxN][maxN];
long long dp[maxN];
long long result=0;

void bfs(long long u){
	queue<long long> q;
	fill(dist[u],dist[u]+maxN,-1);
	dist[u][u]=0;
	q.push(u); 
	while(!q.empty()){
		long long cn=q.front();
		q.pop();
		for(long long a:adj[cn]){
			if(dist[u][a]==-1){
				dist[u][a]=dist[u][cn]+1;
				q.push(a);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("buffet.in");
	ofstream cout("buffet.out");
	cin>>N>>E;
	for(long long i=0;i<N;i++){
		cin>>val[i].first;
		val[i].second=i;
		long long neigh;
		cin>>neigh;
		for(long long j=0;j<neigh;j++){
			long long v;
			cin>>v;
			v--;
			adj[i].push_back(v);
		}
	}

	for(long long i=0;i<N;i++){
		bfs(i);
	}

	sort(val,val+N);

	for(long long i=0;i<N;i++){
		dp[val[i].second]=val[i].first;
		for(long long j=0;j<i;j++){
			if(val[i].first>val[j].first&&di){
				dp[val[i].second]=max(dp[val[i].second],val[i].first+dp[val[j].second]-E*dist[val[i].second][val[j].second]);
			}
		}
	}
	for(int i=0;i<N;i++){
		result=max(result,dp[i]);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/