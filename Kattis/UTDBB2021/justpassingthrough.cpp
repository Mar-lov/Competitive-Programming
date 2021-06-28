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
typedef pair<long long,long long> ii;

#define maxB 505
#define INF 1000000000

long long r,c,n;
long long grid[maxB][maxB];
bool isPass[maxB][maxB];
long long dp[maxB][maxB][15];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>r>>c>>n;
	for(long long i=0;i<r;i++){
		for(long long j=0;j<c;j++){
			cin>>grid[i][j];
			for(long long k=0;k<15;k++){
				dp[j][i][k]=INF;
			}
		}
	}

	for(long long i=1;i<r-1;i++){
		for(long long j=1;j<c-1;j++){
			if(grid[i][j]==-1) continue;
			if(grid[i-1][j]>grid[i][j]&&grid[i+1][j]>grid[i][j]&&grid[i][j-1]<grid[i][j]&&grid[i][j+1]<grid[i][j]&&grid[i-1][j]!=-1&&grid[i+1][j]!=-1&&grid[i][j-1]!=-1&&grid[i][j+1]!=-1){
				isPass[i][j]=true;
				//cout<<"1";
			}else{
				//cout<<"0";
				isPass[i][j]=false;
			}
		}
		//cout<<endl;
	}
	for(long long i=0;i<r;i++){
		if(grid[i][0]!=-1) dp[0][i][0]=grid[i][0];
	}
	for(long long i=1;i<c;i++){
		for(long long j=0;j<r;j++){
			if(grid[j][i]==-1) continue;
			for(long long k=0;k<=n;k++){
				//if(i==5&&j==2&&k==1) cout<<dp[i][j][k]<<endl;
				if(j-1>=0&&grid[j-1][i-1]!=-1) dp[i][j][k+(isPass[j][i]?1:0)]=min(dp[i][j][k+(isPass[j][i]?1:0)],grid[j][i]+dp[i-1][j-1][k]);
				//if(i==5&&j==2&&k==1) cout<<dp[i][j][k]<<endl;
				if(j+1<r&&grid[j+1][i-1]!=-1) dp[i][j][k+(isPass[j][i]?1:0)]=min(dp[i][j][k+(isPass[j][i]?1:0)],grid[j][i]+dp[i-1][j+1][k]);
				//if(i==5&&j==2&&k==1) cout<<dp[i][j][k]<<endl;
				if(grid[j][i-1]!=-1) dp[i][j][k+(isPass[j][i]?1:0)]=min(dp[i][j][k+(isPass[j][i]?1:0)],grid[j][i]+dp[i-1][j][k]);
				//if(i==5&&j==2&&k==1) cout<<dp[i][j][k]<<endl;
			}
		}
	}

/*
	for(long long i=0;i<r;i++){
		for(long long j=0;j<c;j++){
			cout<<dp[j][i][0]<<" ";
		}
		cout<<endl;
	}
*/
	long long result=INF;
	for(long long i=0;i<r;i++){
		result=min(dp[c-1][i][n],result);
	}
	if(result>=INF){
		cout<<"impossible"<<endl;
	}else{
		cout<<result<<endl;
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/