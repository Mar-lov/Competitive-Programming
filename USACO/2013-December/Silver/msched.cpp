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

#define maxN 10005

int N;
pi arr[maxN];
int pdp[maxN];
int dp[maxN];
int result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("msched.in");
	ofstream cout("msched.out");
	cin>>N;
	for(int i=1;i<N+1;i++){
		cin>>arr[i].second>>arr[i].first;
	}
	sort(arr+1,arr+N+1);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=arr[i].first;j++){
			dp[j]=max(pdp[j-1]+arr[i].second,pdp[j]);
			result=max(result,dp[j]);
		}
		for(int j=0;j<=N;j++){
			pdp[j]=dp[j];
			dp[j]=0;
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/