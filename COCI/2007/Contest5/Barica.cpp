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

#define INF 1000000000
#define maxB 100005
#define maxN 300000

struct node{
	int x,y,z;
	int e;
};

int N,K;
node arr[maxN];
node swp[maxN];
int dp[maxN];
int xs[maxB];
int ys[maxB];
int xsl[maxB];
int ysl[maxB];
int p[maxN];
vector<int> ans;

//a comparison function between two nodes by useing their indecies 
bool cmp(node A,node B){
	if(A.x==B.x&&A.y==B.y){
		return A.z<B.z;
	}
	if(A.x==B.x){
		return A.y<B.y;
	}
	return A.x<B.x;
}

void solve(int n){
	if(n==p[n]){
		ans.push_back(n);
		return;
	}
	solve(p[n]);
	ans.push_back(n);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i].x>>arr[i].y>>arr[i].z;
		arr[i].e=i;
		swp[i]=arr[i];
	}
	sort(swp,swp+N,cmp);
	xs[arr[0].x]=arr[0].z;
	ys[arr[0].y]=arr[0].z;
	xsl[arr[0].x]=0;
	ysl[arr[0].y]=0;
	int sp=0;
	while(swp[sp].e!=0) sp++;
	for(int i=sp+1;i<N;i++){
		int ci=swp[i].e;
		int cx=swp[i].x;
		int cy=swp[i].y;
		int cz=swp[i].z;
		if(xs[cx]>=ys[cy]){
			if(xs[cx]>=K){
				dp[ci]=xs[cx]-K+cz;
				p[ci]=xsl[cx];
			}
		}else{
			if(ys[cy]>=K){
				dp[ci]=ys[cy]-K+cz;
				p[ci]=ysl[cy];
			}
		}
		if(dp[ci]>=xs[cx]){
			xs[cx]=dp[ci];
			xsl[cx]=ci;
		}
		if(dp[ci]>=ys[cy]){
			ys[cy]=dp[ci];
			ysl[cy]=ci;
		}
	}
	//find path
	solve(N-1);
	//output answer
	cout<<dp[N-1]<<'\n';
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<arr[ans[i]].x<<" "<<arr[ans[i]].y<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/