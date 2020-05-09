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

#define maxN 50002
#define INF 2000000000
int N;
int arr[maxN];
int dp[2][maxN];
int ans=INF;


int main() {
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		arr[i]*=2;
		dp[0][i]=INF;
		dp[1][i]=INF;
	}
	sort(arr,arr+N);
	for(int it=0;it<2;it++){
		dp[it][0]=-2;
		int j=0;
		for(int i=1;i<N;i++){
			while(j+1<i&&abs(arr[i]-arr[j+1])>dp[it][j+1]+2){
				j++;
			}
			dp[it][i]=min(abs(arr[i]-arr[j]),dp[it][j+1]+2);
		}
		reverse(arr,arr+N);
	}
	reverse(dp[1],dp[1]+N);
	/*
	for(int i=0;i<N;i++){
		cout<<dp[0][i]/2<<" ";
	}
	cout<<'\n';
	for(int i=0;i<N;i++){
		cout<<dp[1][i]/2<<" ";
	}
	cout<<'\n';
	*/
	int i=0;
	int j=N-1;
	while(i<j){
		ans=min(ans,max((arr[j]-arr[i])/2,2+max(dp[0][i],dp[1][j])));
		if(dp[0][i+1]<dp[1][j-1]){
			i++;
		}else{
			j--;
		}
	}
	cout<<ans/2<<"."<<(ans%2?5:0)<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/