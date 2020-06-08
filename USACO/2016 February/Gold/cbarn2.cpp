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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define maxN 101
#define maxK 8
#define INF 2000000000
ll N,K;
ll arr[maxN];
ll dp[maxN][maxN][maxK];
ll result=INF;
int main() {
	ifstream cin("cbarn2.in");
	ofstream cout("cbarn2.out");
	cin>>N>>K;
	for(ll i=0;i<N;i++){
		cin>>arr[i];
	}
	for(ll i=0;i<N;i++){
		dp[i][i][1]=0;
		for(ll j=0;j<N-1;j++){
			dp[i][(i+j+1)%N][1]=dp[i][(i+j)%N][1]+(j+1)*arr[(i+j+1)%N];
			//cout<<i<<" "<<(i+j+1)%N<<" "<<dp[i][(i+j+1)%N][1]<<'\n';
		}
	}
	for(ll k=2;k<=K;k++){
		for(ll s=0;s<N;s++){
			for(ll l=k-1;l<N;l++){
				dp[s][(s+l)%N][k]=INF;
				for(ll h=k-2;h<l;h++){
					dp[s][(s+l)%N][k]=min(dp[s][(s+l)%N][k],dp[s][(s+h)%N][k-1]+dp[(s+h+1)%N][(s+l)%N][1]);
				}
				//cout<<s<<" "<<(s+l)%N<<" "<<k<<" "<<dp[s][(s+l)%N][k]<<'\n';
			}
		}
	}
	for(ll i=0;i<N;i++){
		result=min(result,dp[(i+1)%N][i][K]);
	}
	cout<<result<<'\n';
	return 0;
}
/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/