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

#define maxN 2005
#define INF 1000000000
long long N;
long long A,B;
long long arr[maxN];
double dp[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("wifi.in");
    ofstream cout("wifi.out");
	cin>>N>>A>>B;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+N+1);
    fill(dp,dp+maxN,INF);
    dp[0]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],A+B*((arr[i]-arr[j])/2.0)+dp[j-1]);
        }
    }
    cout<<fixed;
    cout<<((int)dp[N]==dp[N]?setprecision(0):setprecision(1))<<dp[N]<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/