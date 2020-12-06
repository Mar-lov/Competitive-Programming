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

#define maxV 1005
#define MOD 1000000009

long long N,M,K;
long long FJ[maxV];
long long FP[maxV];
long long dp[maxV][maxV][11];
//have a feeling its DP dp[FJ][FP] with modulo checks

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("team.in");
    ofstream cout("team.out");
	cin>>N>>M>>K;
    for(long long i=1;i<=N;i++){
        cin>>FJ[i];
    }
    for(long long i=1;i<=M;i++){
        cin>>FP[i];
    }
    sort(FJ+1,FJ+N+1);
    sort(FP+1,FP+M+1);
    for(long long i=0;i<=N;i++){
        for(long long k=0;k<=K;k++){
            dp[i][0][k]=0;
        }
    }
    for(long long j=0;j<=M;j++){
        for(long long k=0;k<=K;k++){
            dp[0][j][k]=0;
        }
    }
    for(long long i=0;i<=N;i++){
        for(long long j=0;j<=M;j++){
            dp[i][j][0]=1;
        }
    }
    for(long long i=1;i<=N;i++){
        for(long long j=1;j<=M;j++){
            for(long long k=1;k<=K;k++){
                if(FJ[i]>FP[j]){
                    dp[i][j][k]+=dp[i-1][j-1][k-1];
                    dp[i][j][k]%=MOD;
                }
                dp[i][j][k]+=(((dp[i-1][j][k]+dp[i][j-1][k])%MOD)-dp[i-1][j-1][k]);
                while(dp[i][j][k]<0) dp[i][j][k]+=MOD;
                dp[i][j][k]%=MOD;
            }
        }
    }
    cout<<dp[N][M][K]%MOD<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/