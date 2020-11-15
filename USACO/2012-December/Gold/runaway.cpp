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

#define maxN 200005
#define maxB 31

long long N;
long long L;
vector< pi > adj[maxN];
long long bl[maxN][maxB];
long long dt[maxN][maxB];
long long psum[maxN];

void dfs(long long n){
	for(long long i=0;i<adj[n].size();i++){
			dfs(adj[n][i].first);
			psum[n]+=psum[adj[n][i].first];
	}
}

//binary lifting and another one that has the distance travels. Start from leaves. Then prefix sum add one to the start locatin and then -1 to the parent of max distance
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("runaway.in");
	ofstream cout("runaway.out");
	cin>>N>>L;
	bl[1][0]=1;
	dt[1][0]=0;
	long long to,dist;
	//input and setup
	for(long long i=2;i<=N;i++){
		cin>>to>>dist;
		bl[i][0]=to;
		dt[i][0]=dist;
		adj[to].push_back(make_pair(i,dist));
	}

	//sets up binary lifting and total distance
	for(long long j=1;j<maxB;j++){
		for(long long i=1;i<=N;i++){
			//to which node and the distance needed to travel
			bl[i][j]=bl[bl[i][j-1]][j-1];
			dt[i][j]=dt[bl[i][j-1]][j-1]+dt[i][j-1];
		}	
	}

	for(long long n=1;n<=N;n++){
		//cd is current distance left and cn is current node
		long long cd=L;
		long long cn=n;
		//add one to its presum
		psum[n]++;
		for(long long i=maxB-1;i>=0;i--){
			while(cn!=1&&cd-dt[cn][i]>=0){
				cd-=dt[cn][i];
				cn=bl[cn][i];
				//cout<<dt[cn][i]<<" to "<<cn<<" with "<<i<<endl;
			}
		}
		//if not at barn the subtract one from nodes parent psum value
		if(cn!=1){
			psum[bl[cn][0]]--;
		}
	}
	//calculates sums
	dfs(1);
	//output
	for(long long i=1;i<=N;i++){
		cout<<psum[i]<<'\n';
	}

    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/