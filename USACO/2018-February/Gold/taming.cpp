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

#define maxN 105
#define INF 2000000000

int N;
int arr[maxN];
int dp[maxN][maxN][maxN];

int main() {
	ifstream cin("taming.in");
	ofstream cout("taming.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=N;k++){
				dp[i][j][k]=INF;
			}
		}
	}

	if(arr[0]==0){
		dp[0][0][1]=0;
	}else{
		dp[0][0][1]=1;
	}

	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			for(int k=1;k<=i+1;k++){
				if(j<i){
					dp[i][j][k]=dp[i-1][j][k];
				}else{
					for(int z=0;z<i;z++){
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][z][k-1]);
					}
				}
				if(arr[i]!=i-j) dp[i][j][k]++;
			}
		}
	}

	for(int i=1;i<=N;i++){
		int minV=INF;
		for(int j=0;j<N;j++){
			 minV=min(minV,dp[N-1][j][i]);
			 //cout<<i<<" "<<dp[N-1][j][i]<<'\n';
		}
		cout<<minV<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/