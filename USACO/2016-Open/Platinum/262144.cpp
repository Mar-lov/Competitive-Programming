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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define maxN 270000

int N;
int arr[maxN];
int dp[maxN][60];
int result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("262144.in");
	ofstream cout("262144.out");
	cin>>N;
	for(int i=0;i<maxN;i++){
		for(int j=0;j<60;j++){
			dp[i][j]=-1;
		}
	}
	for(int i=1;i<=N;i++){
		cin>>arr[i];
		dp[i][arr[i]]=i;
		result=max(result,arr[i]);
	}
	for(int j=2;j<60;j++){
		for(int i=1;i<=N;i++){
			if(dp[i][j-1]==-1) continue;
			if(dp[dp[i][j-1]+1][j-1]==-1) continue;
			dp[i][j]=dp[dp[i][j-1]+1][j-1];
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			if(dp[i][j]!=-1) result=max(result,j);
		}
	}
	cout<<result<<'\n';



    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/