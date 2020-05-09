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

#define maxN 405
#define INF 1000000000

int N,K;
int arr[maxN];
int subs[maxN][maxN];
int mv[maxN][maxN];
int dp[maxN][maxN];

int main() {
	ifstream cin("snakes.in");
	ofstream cout("snakes.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		mv[i][i]=arr[i];
	}
	for(int i=0;i<=N;i++){
		fill(dp[i],dp[i]+K+1,INF);
	}
	for(int len=1;len<N;len++){
		for(int i=0;i+len<N;i++){
			int m1=mv[i][i];
			int m2=mv[i+1][i+len];
			if(m1>m2){
				subs[i][i+len]=(m1-m2)*(len)+subs[i+1][i+len];
			}else{
				subs[i][i+len]=(m2-m1)*(1)+subs[i+1][i+len];
			}
			mv[i][i+len]=max(m1,m2);
		}
	}
	int cm=subs[0][N-1];
	for(int i=0;i<=K;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=N;i++){
		dp[i][0]=subs[0][i-1];
		//cout<<i<<" "<<0<<" "<<dp[i][0]<<'\n';
		for(int j=1;j<=K;j++){
			for(int k=0;k<i;k++){
			dp[i][j]=min(dp[i][j],dp[k][j-1]+subs[k][i-1]);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}
	}
	cout<<dp[N][K]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/