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

#define maxN 100005

long long N,M,C;
long long mStart[maxN];
vector< pi > adj[maxN];
vector< pi > radj[maxN];
pi mDist[maxN];

bool cmp(pi a,pi b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}

void distDFS(long long n,long long cd){
	mDist[n].first=max(mDist[n].first,cd);
	for(pi a:radj[n]) if(cd+a.second>mDist[a.first].first) {
		distDFS(a.first,cd+a.second);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("timeline.in");
	ofstream cout("timeline.out");
	cin>>N>>M>>C;
	for(long long i=0;i<N;i++){
		cin>>mStart[i];
		mDist[i].second=i;
	}	
	long long a,b,x;
	for(long long i=0;i<C;i++){
		cin>>a>>b>>x;
		a--;
		b--;
		adj[a].push_back(make_pair(b,x));
		radj[b].push_back(make_pair(a,x));
	}

	for(long long i=0;i<N;i++){
		if(adj[i].size()==0) distDFS(i,0);
	}

	sort(mDist,mDist+N,cmp);

	for(long long i=0;i<N;i++){
		pi cur=mDist[i];
		long long cn=cur.second;
		for(pi a:radj[cn]){
			mStart[cn]=max(mStart[cn],mStart[a.first]+a.second);
		}
	}
	for(long long i=0;i<N;i++){
		cout<<mStart[i]<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/