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

#define maxN 1005
#define INF 2000000000

long long N;
long long arr[maxN];
//[left most][cows includes][left:right]
long long dp[maxN][maxN][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("cowrun.in");
    ofstream cout("cowrun.out");
    cin>>N;
    for(long long i=1;i<=N;i++){
        cin>>arr[i];
    }
    N++;
    arr[N+1]=0;
    sort(arr+1,arr+N+1);

    for(long long i=0;i<=N;i++){
        for(long long j=0;j<=N;j++){
            dp[i][j][0]=INF;
            dp[i][j][1]=INF;
        }
        if(arr[i]==0){
            dp[i][1][0]=0;
            dp[i][1][1]=0;
        }
    }
    for(long long len=1;len<N;len++){
        long long nnsc=N-len;
        for(long long i=1;i+len<=N+1;i++){
            //add to left
            dp[i-1][len+1][0]=min(dp[i][len][0]+nnsc*abs(arr[i-1]-arr[i]),dp[i][len][1]+nnsc*abs(arr[i-1]-arr[i+len-1]));
            //add to right
            dp[i][len+1][1]=min(dp[i][len][0]+nnsc*abs(arr[i]-arr[i+len]),dp[i][len][1]+nnsc*abs(arr[i+len-1]-arr[i+len]));
        }
    }

    cout<<min(dp[1][N][0],dp[1][N][1])<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/