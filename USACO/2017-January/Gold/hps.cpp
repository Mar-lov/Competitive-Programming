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
int arr[100005];
int dp[100005][21][3];

int main() {
	ifstream cin("hps.in");
	ofstream cout("hps.out");
	cin>>N>>K;
	char move;
	for(int i=0;i<N;i++){
		cin>>move;
		if(move=='H') arr[i]=0;
		if(move=='P') arr[i]=1;
		if(move=='S') arr[i]=2;
	}

	for(int i=0;i<=N;i++){
		for(int j=0;j<=K;j++){
			for(int s=0;s<3;s++){
				if(i==0){
					dp[i][j][s]=0;
				}else{
				if(j==0){
					dp[i][j][s]=dp[i-1][j][s]+(arr[i-1]==s?1:0);
				}else{
					int os1=(s+1)%3;
					int os2=(s+2)%3;
					dp[i][j][s]=max(dp[i-1][j][s],max(dp[i-1][j-1][os1],dp[i-1][j-1][os2]))+(arr[i-1]==s?1:0);
				}
				}
			}
		}
	}
	cout<<max(dp[N][K][0],max(dp[N][K][1],dp[N][K][2]))<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/