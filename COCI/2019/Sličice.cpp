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

#define maxV 505

int N,M,K;
int P[maxV];
int B[maxV];
int dp[maxV][maxV];
int result=0;
int pval(int n){
	if(n>=M) return B[M];
	return B[n];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		cin>>P[i+1];
	}
	for(int i=0;i<=M;i++){
		cin>>B[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<=K;j++){
			for(int z=0;z<=j;z++){
				dp[i][j]=max( dp[i][j] , dp[i-1][z]+pval(P[i]+(j-z)) );
			}
			result=max(result,dp[i][j]);
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/