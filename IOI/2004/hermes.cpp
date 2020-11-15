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
typedef pair<ll,ll> pi;

#define maxN 20005
#define INF (ll)1000000000

ll N;
pair<ll,ll> arr[maxN];
ll dp[maxN][2];
ll xc[maxN];
ll yc[maxN];
ll sx[maxN];
ll sy[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(ll i=0;i<maxN;i++){
		dp[i][0]=INF;
		dp[i][1]=INF;
	}
	for(ll i=1;i<=N;i++){
		cin>>arr[i].first>>arr[i].second;
		sx[i]=arr[i].first;
		sy[i]=arr[i].second;
	}
	for(ll i=1;i<=N;i++){
		xc[i]=abs(arr[i].first-arr[i-1].first)+xc[i-1];
		yc[i]=abs(arr[i].second-arr[i-1].second)+yc[i-1];
	}
	//0 end on x 1 end on y
	dp[0][0]=0;
	dp[0][1]=0;
	for(ll i=1;i<=N;i++){
		for(ll j=0;j<i;j++){
			//dp[i][0]=min(dp[i][0],dp[j][1]+(xc[i]-xc[j]));
			if(dp[i][0]>dp[j][1]+(xc[i]-xc[j])+abs(arr[j].first-sx[j])){
				dp[i][0]=dp[j][1]+(xc[i]-xc[j])+abs(arr[j].first-sx[j]);
				sy[i]=sy[j];
			}
			//dp[i][1]=min(dp[i][1],dp[j][0]+(yc[i]-yc[j]));
			if(dp[i][1]>dp[j][0]+(yc[i]-yc[j])+abs(arr[j].second-sy[j])){
				dp[i][1]=dp[j][0]+(yc[i]-yc[j])+abs(arr[j].second-sy[j]);
				sx[i]=sx[j];
			}
		}
		cout<<i<<" :"<<dp[i][0]<<" & "<<dp[i][1]<<'\n';
		cout<<"   "<<sy[i]<<"   "<<sx[i]<<'\n';
	}
	cout<<min(dp[N][0],dp[N][1])<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/