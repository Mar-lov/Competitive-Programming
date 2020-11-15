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
typedef pair<long long,long long> pi;

#define maxN 500000

long long N;
pair<long long,long long> arr[maxN];
long long dp[maxN];
long long result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+N);
	dp[0]=arr[0].second;
	for(int i=1;i<N;i++){
		dp[i]=arr[i].second+max((long long)0,dp[i-1]-arr[i].first+arr[i-1].first);
	}
	for(int i=0;i<N;i++){
		result=max(dp[i],result);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/