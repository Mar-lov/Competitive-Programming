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

#define MOD 1000000007
#define maxV 1000005
ll N,M,K;
ll dp[maxV];
ll result=1;

int main() {
	ifstream cin("spainting.in");
	ofstream cout("spainting.out");

	cin>>N>>M>>K;
	dp[0]=0;
	for(int i=1;i<K;i++){
		dp[i]=dp[i-1]*M+M;
		dp[i]%=MOD;
		//cout<<dp[i]<<'\n';
	}
	for(int i=K;i<=N;i++){
		dp[i]=((M*dp[i-1])%MOD)+MOD-(((M-1)*dp[i-K])%MOD);
		dp[i]%=MOD;
	}

	for(int i=0;i<N;i++){
		result*=M;
		result%=MOD;
	}
	cout<<(result+MOD-(dp[N]-dp[N-1]))%MOD<<'\n';


	return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/