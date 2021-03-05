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
typedef pair< pair<int,int>,int > pii;
#define f first
#define s second

#define maxN 1005
#define INF 1000000009

int N;
vector< pii > north;
vector< pii > east;
int dist[maxN];
vector<int> adj[maxN];
int result[maxN];
int visited[maxN];

int solve(int n){
	if(visited[n]) return result[n];
	visited[n]=true;
	for(int a:adj[n]){
		result[n]+=1+solve(a);
	}
	return result[n];
}

bool cmpx(pii a,pii b){
	return a.f.f<b.f.f;
}
bool cmpy(pii a,pii b){
	return a.f.s<b.f.s;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	char cc;
	int ix,iy;
	for(int i=0;i<N;i++){
		cin>>cc>>ix>>iy;
		if(cc=='N') north.push_back( make_pair( make_pair(ix,iy),i) );
		else if(cc=='E') east.push_back( make_pair( make_pair(ix,iy),i) );
	}
	fill(dist,dist+N,INF);
	sort(east.begin(),east.end(),cmpy);
	sort(north.begin(),north.end(),cmpx);

	for(int i=0;i<north.size();i++){
		for(int j=0;j<east.size();j++){
			if(!(north[i].f.f>east[j].f.f&&north[i].f.s<east[j].f.s)) continue;
			if(east[j].f.f+dist[east[j].s]<north[i].f.f) continue;
			if(north[i].f.s+dist[north[i].s]<east[j].f.s) continue;
			if((north[i].f.f-east[j].f.f)<(east[j].f.s-north[i].f.s)){
				dist[north[i].s]=east[j].f.s-north[i].f.s;
				adj[east[j].s].push_back(north[i].s);
				//cout<<east[j].s<<" took out "<<north[i].s<<'\n';
			}
			if((north[i].f.f-east[j].f.f)>(east[j].f.s-north[i].f.s)){
				dist[east[j].s]=(north[i].f.f-east[j].f.f);
				adj[north[i].s].push_back(east[j].s);
				//cout<<north[i].s<<" took out "<<east[j].s<<'\n';
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<solve(i)<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/