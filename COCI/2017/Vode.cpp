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

#define maxV 5005

int N,M,K;
int arr[maxV];
int dp[maxV][maxV];
int psum[maxV][maxV];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		fill(dp[i],dp[i]+maxV,-1);
	}
	for(int i=0;i<N;i++){
		cin>>arr[i];
		dp[i][M]=1-arr[i];
		psum[i][M]=1-arr[i];
	}
	for(int j=M-1;j>=0;j--){
		for(int i=0;i<N;i++){
			int pvs=psum[(i+1)%N][j+1]-psum[(i+1)%N][min(M+1,j+1+K)];
			if(pvs==0){
				dp[i][j]=0;
			}else if(pvs==K||(j>M-K&&pvs==M-j)){
				dp[i][j]=1;
			}else{
				dp[i][j]=arr[(i+1)%N];
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<'\n';
		for(int i=0;i<N;i++){
			psum[i][j]=dp[i][j]+psum[i][j+1];
		}
	}
	for(int i=0;i<N;i++){
		cout<<dp[(i+N-1)%N][0]<<" ";
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/