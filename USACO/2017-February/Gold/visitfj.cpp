/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair< ll , pi > pii;

#define maxN 105
#define INF (1LL<<55)

ll N,T;
ll arr[maxN][maxN];
ll mdist[maxN][maxN];
ll minD=INF;
//first 12 are 3 away next 4 are 1(still counts as 3 moves)
int dx[]={0,0,-1,-1,1,1,-2,-2,2,2,-3,3,0,-1,0,1};
int dy[]={-3,3,-2,2,-2,2,-1,1,-1,1,0,0,-1,0,1,0};


int main() {
	ifstream cin("visitfj.in");
	ofstream cout("visitfj.out");
	cin>>N>>T;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			mdist[i][j]=INF;
		}
	}
	mdist[0][0]=0;
	priority_queue<pii,vector<pii> , greater<pii> > q;
	q.push(make_pair(0,make_pair(0,0)));
	while(!q.empty()){
		pii cl=q.top();q.pop();
		ll cd=cl.first;
		int i=cl.second.first;
		int j=cl.second.second;
		if(cd>mdist[i][j]) continue;
		if(((N-i-1)+(N-j-1))<3) minD=min(minD,cd+T*((N-i-1)+(N-j-1)));
		for(int k=0;k<16;k++){
			if(i+dx[k]>=0&&i+dx[k]<N&&j+dy[k]>=0&&j+dy[k]<N&&mdist[i+dx[k]][j+dy[k]]>=cd+arr[i+dx[k]][j+dy[k]]+3*T){
				mdist[i+dx[k]][j+dy[k]]=cd+arr[i+dx[k]][j+dy[k]]+3*T;
				q.push(make_pair(mdist[i+dx[k]][j+dy[k]],make_pair(i+dx[k],j+dy[k])));
			}
		}
	}
	/**
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<mdist[i][j]<<" ";
		}
		cout<<'\n';
	}
	**/
	cout<<min(minD,mdist[N-1][N-1]);
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/