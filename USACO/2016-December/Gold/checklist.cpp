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
typedef pair<ll,ll> pi;

int H,G;
pi hl[1005];
pi gl[1005];
ll dp[1005][1005][2];

ll dist(pi a,pi b){
	return ((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second));
}

int main() {
	ifstream cin("checklist.in");
	ofstream cout("checklist.out");
	cin>>H>>G;
	for(int i=0;i<H;i++){
		cin>>hl[i].first>>hl[i].second;
	}	
	for(int j=0;j<G;j++){
		cin>>gl[j].first>>gl[j].second;
	}

	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			dp[i][j][0]=100000000000000;
			dp[i][j][1]=100000000000000;
		}
	}
	dp[1][0][0]=0;
	for(int i=0;i<=H;i++){
		for(int j=0;j<=G;j++){
			for(int l=0;l<2;l++){
				if(i==0&&l==0) continue;
				if(l==1&&j==0) continue;
				pi sr;
				if(l==0){
					sr=hl[i-1];
				}else{
					sr=gl[j-1];
				}
				if(i<H){
					dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][l]+dist(sr,hl[i]));
				}
				if(j<G){
					dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][l]+dist(sr,gl[j]));
				}
			}
		}
	}
	cout<<dp[H][G][0]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/