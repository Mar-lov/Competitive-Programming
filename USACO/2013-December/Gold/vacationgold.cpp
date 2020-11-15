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

#define maxN 20005
#define maxK 201
#define INF 2000000000

long long N,M,K,Q;
vector< pair<long long,long long> > adj[maxN];
vector< pair<long long,long long> > radj[maxN];
long long hubs[maxK];
long long md[maxN][maxK];
long long tp=0;
long long tl=0;

priority_queue< pair<long long,long long> , vector< pair<long long,long long> > , greater< pair<long long,long long> > > pq;
bool visited[maxN];
void dijkstras(long long s){
	fill(visited,visited+maxN,false);
	pq.push(make_pair(0,s));
	md[s][s]=0;
	while(!pq.empty()){
		long long cd=pq.top().first;
		long long cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		visited[cn]=true;
		for(long long i=0;i<adj[cn].size();i++){
			if(cd+adj[cn][i].second<md[s][adj[cn][i].first]){
				md[s][adj[cn][i].first]=cd+adj[cn][i].second;
				pq.push(make_pair(md[s][adj[cn][i].first],adj[cn][i].first));
			}
		}
	}
}

void rdijkstras(long long s){
	fill(visited,visited+maxN,false);
	pq.push(make_pair(0,s));
	md[s][s]=0;
	while(!pq.empty()){
		long long cd=pq.top().first;
		long long cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		visited[cn]=true;
		for(long long i=0;i<radj[cn].size();i++){
			if(cd+radj[cn][i].second<md[radj[cn][i].first][s]){
				md[radj[cn][i].first][s]=cd+radj[cn][i].second;
				pq.push(make_pair(md[radj[cn][i].first][s],radj[cn][i].first));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("vacationgold.in");
	ofstream cout("vacationgold.out");
	cin>>N>>M>>K>>Q;
	for(long long i=0;i<maxN;i++){
		for(long long j=0;j<maxK;j++){
			md[i][j]=INF;
		}
	}
	long long ui,vi,di;
	for(long long i=0;i<M;i++){
		cin>>ui>>vi>>di;
		ui--;
		vi--;
		adj[ui].push_back(make_pair(vi,di));
		radj[vi].push_back(make_pair(ui,di));
	}
	for(long long i=0;i<K;i++){
		cin>>hubs[i];
		hubs[i]--;
	}


	for(long long i=0;i<K;i++){
		dijkstras(hubs[i]);
		rdijkstras(hubs[i]);
	}

	long long s,e;
	for(long long i=0;i<Q;i++){
		cin>>s>>e;
		s--;
		e--;
		long long cmd=INF;
		for(long long j=0;j<K;j++){
			cmd=min(cmd,md[s][hubs[j]]+md[hubs[j]][e]);
		}
		//cout<<cmd<<'\n';
		if(cmd<INF){
			tp++;
			tl+=cmd;
		}
	}
	cout<<tp<<"\n"<<tl<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/