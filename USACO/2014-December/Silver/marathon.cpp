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

int N,K;
pi check[500];
int dp[500][500];
int distto(int i1,int i2){
	return abs(check[i1].first-check[i2].first)+abs(check[i1].second-check[i2].second);
}

int main() {
	ifstream cin("marathon.in");
	ofstream cout("marathon.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>check[i].first>>check[i].second;
	}
	//distance travels it gotten to by j skips
	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++){
			dp[i][j]=(1<<30);
		}
	}
	dp[0][0]=0;
	for(int i=0;i<=K;i++){
		for(int j=0;j<N;j++){
			for(int l=j+1;l<N&&i+l-j-1<=K;l++){
				int hms=i+(l-j-1);
				int st=l;
				dp[hms][st]=min(dp[hms][st],dp[i][j]+distto(j,l));

			}
		}
	}
	cout<<dp[K][N-1]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/