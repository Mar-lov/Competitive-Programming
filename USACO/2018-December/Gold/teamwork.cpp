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

#define maxN 10005

int N,K;
int sum[maxN][maxN];
int dp[maxN];

int main() {
	ifstream cin("teamwork.in");
	ofstream cout("teamwork.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>sum[i][i];
	}
	for(int k=1;k<K;k++){
		for(int j=k;j<N;j++){
			sum[j-k][j]=(k+1)*max(sum[j-k][j-1]/(k),sum[j-k+1][j]/(k));
		}
	}

	dp[0]=sum[0][0];
	for(int i=0;i<N;i++){
		for(int j=i;j>=0&&j>i-K;j--){
		dp[i]=max(dp[i],dp[j-1]+sum[j][i]);
		}
	}
	cout<<dp[N-1]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/