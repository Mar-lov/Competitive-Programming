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

#define maxN 305
#define INF 1000000000
int N;
int arr[maxN];
int dp[maxN][maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dp[i][j]=INF;
		}
	}

	for(int i=0;i<N;i++){
		dp[i][i]=1;
	}

	//doesnt account for same inside 1 FCUK
	
	for(int d=1;d<N;d++){
		for(int i=0;i+d<N;i++){
			int j=i+d;		
			int works=true;
			int num=0;
			for(int k=i;k<=((i+j)/2);k++){
				if(arr[k]==arr[j-(k-i)]&&k!=j-(k-i)) num++;
				else works=false;
				//if(i==0&&j==8) cout<<i<<":"<<k<<" "<<dp[i][k]<<" & "<<k+1<<" "<<j<<" "<<dp[k+1][j]<<" "<<(works?num:0)<<endl;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-(works?num:0));
			}
			works=true;
			num=0;
			for(int k=j;k>((i+j)/2);k--){
				if(arr[k]==arr[j-(k-i)]&&k!=j-(k-i)) num++;
				else works=false;
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]-(works?num:0));
			}
			//cout<<i<<" to "<<j<<" = "<<dp[i][j]<<endl;
		}
	}

	cout<<dp[0][N-1]<<'\n';
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/