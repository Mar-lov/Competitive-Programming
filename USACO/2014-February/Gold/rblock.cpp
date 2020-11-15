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

#define INF 2000000000
#define maxN 255

int N,M;
int adjm[maxN][maxN];
int startdist=0;
int nmd=0;

int dist[maxN];
bool visited[maxN];
int pre[maxN];
priority_queue< pair< int, int> , vector< pair< int, int > > , greater< pair<int,int> > > pq;
void dijkstras(int s){
	fill(dist,dist+maxN,INF);
	fill(visited,visited+maxN,false);
	fill(pre,pre+maxN,-1);
	pre[s]=s;
	dist[s]=0;
	pq.push( make_pair(0,s) );
	while(!pq.empty()){
		int cd=pq.top().first;
		int cn=pq.top().second;
		pq.pop();
		if(visited[cn]) continue;
		visited[cn]=true;
		for(int i=1;i<=N;i++){
			if(cd+adjm[cn][i]<dist[i]){
				dist[i]=cd+adjm[cn][i];
				pre[i]=cn;
				pq.push(make_pair(dist[i],i));
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("rblock.in");
	ofstream cout("rblock.out");
	for(int i=0;i<maxN;i++){
		fill(adjm[i],adjm[i]+maxN,INF);
	}

	cin>>N>>M;
	int a,b,cdist;
	for(int i=0;i<M;i++){
		cin>>a>>b>>cdist;
		adjm[a][b]=cdist;
		adjm[b][a]=cdist;
	}
	dijkstras(1);
	startdist=dist[N];

	vector< pair<int, pair<int,int> > > cnts;
	int cn=N;

	while(cn!=pre[cn]){
		cnts.push_back( make_pair(adjm[cn][pre[cn]],make_pair(cn,pre[cn])));
		cn=pre[cn];
	}
	sort(cnts.begin(),cnts.end());

	for(int mid=0;mid<cnts.size();mid++){
		a=cnts[mid].second.first;
		b=cnts[mid].second.second;
		adjm[a][b]*=2;
		adjm[b][a]*=2;
		dijkstras(1);
		int ncd=dist[N];
		nmd=max(nmd,ncd);
		adjm[a][b]/=2;
		adjm[b][a]/=2;
	}
	
	cout<<nmd-startdist<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/