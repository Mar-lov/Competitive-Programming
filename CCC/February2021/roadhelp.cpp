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
typedef pair<long long,long long> ii;

#define maxN 1005
#define maxM 2005
#define MOD 1000000007

long long add(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long sum=a+b;
	sum%=MOD;
	return sum;
}


long long N,M;
vector< ii > adj[maxN];
long long result[maxM];
long long len[maxM];

stack<long long> fv;
long long pseen[maxN];
long long dist[maxN];
bool visited[maxN];
priority_queue< ii , vector<ii> , greater<ii> > pq;

void dijkstras(long long start){
	fill(dist,dist+maxN,MOD);
	fill(visited,visited+maxN,false);
	dist[start]=0;
	pq.push(make_pair(0,start));
	while(!pq.empty()){
		long long cd=pq.top().first;
		long long cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		fv.push(cn);
		visited[cn]=true;
		for(ii nv:adj[cn]){
			long long nn=nv.first;
			long long ce=nv.second;
			if(dist[cn]+len[ce]<dist[nn]){
				dist[nn]=dist[cn]+len[ce];
				pq.push(make_pair(dist[nn],nn));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("roadhelp.in");
	ofstream cout("roadhelp.out");
	cin>>N>>M;
	long long u,v,w;
	for(long long i=0;i<M;i++){
		cin>>u>>v>>w;
		u--;
		v--;
		len[i]=w;
		adj[u].push_back(make_pair(v,i));
		adj[v].push_back(make_pair(u,i));
	}

	//go through each node
	for(long long i=0;i<N;i++){
		dijkstras(i);
		fill(pseen,pseen+maxN,1);
		while(!fv.empty()){
			long long cn=fv.top();
			fv.pop();
			for(ii nv:adj[cn]){
				long long nn=nv.first;
				long long ce=nv.second;
				if(dist[cn]-len[ce]==dist[nn]){
					result[ce]=add(result[ce],pseen[cn]);
					pseen[nn]=add(pseen[nn],pseen[cn]);
				}
			}
		}
	}

	for(long long i=0;i<M;i++){
		cout<<result[i]%MOD<<endl;
	}

    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/