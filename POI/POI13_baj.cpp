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

#define maxN 1000005
#define INF 1000000000
int N;
int arr[maxN];
int dp[maxN][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		arr[i]++;
		dp[i][0]=INF;
		dp[i][1]=INF;
		dp[i][2]=INF;
	}
	dp[0][arr[0]]=0;
	for(int i=1;i<N;i++){
		if(arr[i]==0){
			dp[i][0]=dp[i-1][0];
			dp[i][2]=dp[i-1][2]+2;
		}else if(arr[i]==1){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
			dp[i][2]=dp[i-1][2]+1;
		}else if(arr[i]==2){
			dp[i][0]=dp[i-1][0]+2;
			dp[i][1]=dp[i-1][0]+1;
			dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
		}
	}
	int result=min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2]));
	if(result>=INF){
		cout<<"BRAK"<<'\n';
	}else{
	cout<<result<<'\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/