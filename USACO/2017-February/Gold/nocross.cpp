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

int N;
int f[1005];
int s[1005];
int dp[1005][1005];

int main() {
	ifstream cin("nocross.in");
	ofstream cout("nocross.out");
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>f[i];
	}
	for(int j=1;j<=N;j++){
		cin>>s[j];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(abs(f[i]-s[j])<=4));
		}
	}
	cout<<dp[N][N]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/