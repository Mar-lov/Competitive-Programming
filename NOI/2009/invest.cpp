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

#define maxM 1005

int M;
int psum[maxM][5];
int cost[5];
int dp[maxM][5];
int result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>M;

	for(int i=1;i<=M;i++){
		for(int j=0;j<5;j++){
			cin>>psum[i][j];
		}
	}

	for(int i=0;i<5;i++){
		cin>>cost[i];
	}

	for(int i=1;i<=M;i++){
		for(int j=0;j<5;j++){
			psum[i][j]=2520/psum[i][j];
			psum[i][j]*=cost[j];
			psum[i][j]+=psum[i-1][j];
		}
	}
	for(int i=1;i<=min(M,15);i++){
		for(int j=0;j<5;j++){
			dp[i][j]=psum[i][j];
			result=max(result,dp[i][j]);
		}
	}
	for(int i=0;i<=M;i++){

		for(int k=0;k<5;k++){
			for(int l=0;l<5;l++){
				if(i<15&&k!=l) continue;
				for(int j= (k==l?1:14) ;i+j<=M;j++){
					dp[i+j][l]=max(dp[i+j][l],dp[i][k]+psum[i+j][l]-psum[i][l]);
				}
			}
		}
	}
	for(int k=0;k<5;k++){
		result=max(result,dp[M][k]);
	}
	cout<<result<<'\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/