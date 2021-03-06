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

#define maxN 10005

int N,K;
int arr[maxN];
int dp[maxN];

int main() {
	ifstream cin("teamwork.in");
	ofstream cout("teamwork.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N;i++){
		int cm=0;
		for(int j=i;j>=0&&j>i-K;j--){
			// running sum
			cm=max(cm,arr[j]);
		dp[i]=max(dp[i],dp[j-1]+cm*(i-j+1));
		}
	}
	cout<<dp[N-1]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/