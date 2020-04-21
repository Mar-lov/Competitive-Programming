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

int N,M;
string fp,bp;
pi fl[1001];
pi bl[1001];
int dp[1005][1005];

int dist(int fi,int bi){
	return pow(fl[fi].first-bl[bi].first,2)+pow(fl[fi].second-bl[bi].second,2);
}

int main() {
	ifstream cin("radio.in");
	ofstream cout("radio.out");
	cin>>N>>M;
	cin>>fl[0].first>>fl[0].second;
	cin>>bl[0].first>>bl[0].second;
	cin>>fp;
	cin>>bp;
	int xc,yc;
	for(int i=0;i<N;i++){
		if(fp[i]=='N'){
			xc=0;
			yc=1;
		}else if(fp[i]=='E'){
			xc=1;
			yc=0;
		}else if(fp[i]=='S'){
			xc=0;
			yc=-1;
		}else if(fp[i]=='W'){
			xc=-1;
			yc=0;
		}
		fl[i+1].first=fl[i].first+xc;
		fl[i+1].second=fl[i].second+yc;
	}
	for(int i=0;i<M;i++){
		if(bp[i]=='N'){
			xc=0;
			yc=1;
		}else if(bp[i]=='E'){
			xc=1;
			yc=0;
		}else if(bp[i]=='S'){
			xc=0;
			yc=-1;
		}else if(bp[i]=='W'){
			xc=-1;
			yc=0;
		}
		bl[i+1].first=bl[i].first+xc;
		bl[i+1].second=bl[i].second+yc;
	}
	dp[0][0]=0;
	for(int i=1;i<=N;i++) dp[i][0]=dist(i,0)+dp[i-1][0];
	for(int j=1;j<=M;j++) dp[0][j]=dist(0,j)+dp[0][j-1];

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			dp[i][j]=(1<<31);
			dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+dist(i,j);
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
		}
	}

	cout<<dp[N][M]<<"\n";
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/