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
int arr[250];
int dp[250][250];

int main() {
	ifstream cin("248.in");
	ofstream cout("248.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	int maxV=0;
	for(int len=1;len<=N;len++){
		for(int i=0;i+len<=N;i++){
			int j=i+len-1;
			dp[i][j]=-1;
			if(len==1){
				dp[i][j]=arr[i];
			}
			for(int k=i;k<j;k++){
				if(dp[i][k]==dp[k+1][j]&&dp[i][k]>0){
					dp[i][j]=max(dp[i][j],dp[i][k]+1);
				}
			}
			maxV=max(maxV,dp[i][j]);
		}
	}
	cout<<maxV<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/