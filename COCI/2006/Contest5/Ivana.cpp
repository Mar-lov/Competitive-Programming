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

#define maxN 105

int N;
int arr[maxN];
int to=0;
int dp[maxN][maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		if(arr[i]%2==1) to++;
	}
	if(N%2==1){
		for(int i=0;i<N;i++){
			if(arr[i]%2==1) dp[i][i]=1;
		}
	}
	int cm=N-1;
	for(int k=1;k<N-1;k++){
		for(int i=0;i<N;i++){
			int j=(i+k)%N;
			//his
			if(cm%2==0){
				dp[i][j]=min(dp[i][(j+N-1)%N],dp[(i+1)%N][j]);
			}else{
				dp[i][j]=max(dp[i][j],dp[i][(j+N-1)%N]+(arr[j]%2==1?1:0));
				dp[i][j]=max(dp[i][j],dp[(i+1)%N][j]+(arr[i]%2==1?1:0));
			}
		}
		cm--;
	}
	int result=0;
	for(int i=0;i<N;i++){
		if(dp[(i+1)%N][(i+N-1)%N]+(arr[i]%2==1?1:0)>(to/2)) result++;
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/