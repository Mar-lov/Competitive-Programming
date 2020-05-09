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
typedef pair<ll,ll> pi;
const ll maxN =255;
const ll maxW =1001;
const ll INF =1000000000;
ll N,W;
ll w[maxN];
ll t[maxN];

ll val[maxN];
ll dp[maxN][maxW];
bool doable(ll y){
	for(ll i=0;i<=N;i++){
		val[i]=1000*t[i]-y*w[i];
		for(ll j=0;j<=W;j++){
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=0;
	for(ll i=0;i<N;i++){
		for(ll j=0;j<=W;j++){
			ll cw=min(W,j+w[i+1]);
			dp[i+1][cw]=max(dp[i+1][cw],dp[i][j]+val[i+1]);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	}
	return (dp[N][W]>=0);
}

int main() {
	ifstream cin("talent.in");
	ofstream cout("talent.out");
	cin>>N>>W;
	for(ll i=1;i<=N;i++){
		cin>>w[i]>>t[i];
	}
	ll lo=0;
	ll hi=1000000;
	while(lo<hi){
		ll mid=(lo+hi+1)/2;
		if(doable(mid)) lo=mid;
		else hi=mid-1;
	}
	cout<<lo<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/