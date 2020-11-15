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

#define maxV 51
#define INF 100000000
long long N,M;
long long arr[maxV][maxV];
long long dp[maxV][maxV][maxV][maxV];

long long psum(long long a,long long b,long long x,long long y){
	return arr[x][y]-(a-1>=0?arr[a-1][y]:0)-(b-1>=0?arr[x][b-1]:0)+((b-1>=0&&a-1>=0)?arr[a-1][b-1]:0);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
	for(long long i=0;i<N;i++){
		for(long long j=0;j<M;j++){
			for(long long a=i;a<N;a++){
				for(long long b=j;b<M;b++){
					dp[i][j][a][b]=INF;
				}
			}
		}
	}
	for(long long i=0;i<N;i++){
		for(long long j=0;j<M;j++){
			cin>>arr[i][j];
			if(i>0) arr[i][j]+=arr[i-1][j];
			if(j>0) arr[i][j]+=arr[i][j-1];
			if(i>0&&j>0) arr[i][j]-=arr[i-1][j-1];
			dp[i][j][i][j]=0;
		}
	}
	//loc size
	for(long long a=0;a<N;a++){
		for(long long b=0;b<M;b++){
			//starting loc x,y
			for(long long x=0;x+a<N;x++){
				for(long long y=0;y+b<M;y++){
					//splits
					//1D
					for(long long i=1;i<=a;i++){
						dp[x][y][x+a][y+b]=min(dp[x][y][x+a][y+b],dp[x][y][x+i-1][y+b]+dp[x+i][y][x+a][y+b]+psum(x,y,x+a,y+b));
					}
					//2d
					for(long long i=1;i<=b;i++){
						dp[x][y][x+a][y+b]=min(dp[x][y][x+a][y+b],dp[x][y][x+a][y+i-1]+dp[x][y+i][x+a][y+b]+psum(x,y,x+a,y+b));
					}
				}
			}

		}
	}
	cout<<dp[0][0][N-1][M-1]<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/