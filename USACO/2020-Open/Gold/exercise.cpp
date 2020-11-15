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

#define maxP 1235
#define maxN 10005

ll N,M;
ll dp[maxP][maxN];

ll add(ll a,ll b){
	a+=b;
	if(a>M) a-=M;
	return a;
}
ll sub(ll a,ll b){
	a-=b;
	if(a<0)a+=M;
	return a;
}
ll mult(ll a,ll b){
	return (a*b)%M;
}

int main() {
	ifstream cin("exercise.in");
	ofstream cout("exercise.out");
	cin>>N>>M;

	vector<bool> comp(N+1);
	vector<int> primes;
	for(int i=2;i<=N;i++){
		if(!comp[i]){
			primes.push_back(i);
		}
		for(int j=2*i;j<=N;j+=i){
			comp[j]=true;
		}
	} 

	for(int i=0;i<=N;i++){
		dp[0][i]=1;
	}

	for(int i=1;i<=primes.size();i++){
		for(int j=0;j<=N;j++){
			dp[i][j]=dp[i-1][j];
			int cp=primes[i-1];
			while(cp<=j){
				dp[i][j]=add(dp[i][j],mult(cp,dp[i-1][j-cp]));
				cp*=primes[i-1];
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<'\n';
	}

	cout<<dp[primes.size()][N]<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/