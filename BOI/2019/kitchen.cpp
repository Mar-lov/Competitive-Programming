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
 
#define maxV 305
#define INF 1000000000
 
int N,M,K;
int A[maxV];
int B[maxV];
int dp[maxV][maxV*maxV];
int mina=maxV;
int At=0;
int Bt=0;
int result=INF;
//dp values and value after chef i works on it
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<maxV;i++){
		fill(dp[i],dp[i]+(maxV*maxV),-INF);
	}
	for(int i=1;i<=N;i++){
		cin>>A[i];
		mina=min(mina,A[i]);
		At+=A[i];
	}
	if(mina<K){
		cout<<"Impossible"<<'\n';
		return 0;
	}
	for(int i=1;i<=M;i++){
		cin>>B[i];
		Bt+=B[i];
	}
	dp[0][0]=0;
	for(int i=1;i<=M;i++){
		for(int j=0;j<B[i];j++){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=B[i];j<=Bt;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-B[i]]+min(B[i],N));
			//cout<<i<<" "<<j<<" : "<<dp[i][j]<<'\n';
		}
	}
	for(int i=At;i<=Bt;i++){
		if(dp[M][i]>=N*K){
			result=min(result,i-At);
		}
	}

	if(result==INF){
		cout<<"Impossible"<<'\n';
		return 0;
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