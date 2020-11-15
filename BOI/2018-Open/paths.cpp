/*
Code by @marlov       
*/
//https://github.com/updown2/OI-Practice/blob/master/BOI%20(Baltic)/2018/Paths.cpp 
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

#define maxN 300000

long long N,M,K;
long long color[maxN];
vector<long long> adj[maxN];
long long dp[maxN][32];
long long result=0;

void solve(long long n,long long c){
    if(dp[n][c]!=-1) return;
    long long clc=color[n];
    if(((1<<clc)&c)>0){
        dp[n][c]=0;
        return;
    }
    dp[n][c]=1;
    long long nl=(1<<clc)|c;
    long long ret=0;
    for(long long i:adj[n]){
        solve(i,nl);
        ret+=dp[i][nl];
    }
    dp[n][c]+=ret;
    return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
    for(long long i=0;i<N;i++){
        cin>>color[i];
        color[i]--;
        for(long long j=0;j<32;j++){
            dp[i][j]=-1;
        }
    }
    long long u,v;
    for(long long i=0;i<M;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(long long i=0;i<N;i++){
        solve(i,0);
        result+=dp[i][0];
    }
    result-=N;
    cout<<result<<'\n';
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/