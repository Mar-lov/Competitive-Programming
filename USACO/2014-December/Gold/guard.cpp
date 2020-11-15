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

#define maxN 21
#define INF 2000000000
struct cow{
	long long h,w,s;
};

long long N,H;
cow arr[maxN];
long long dp[(1<<maxN)];
long long result=-1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("guard.in");
	ofstream cout("guard.out");
	cin>>N>>H;
	for(long long i=0;i<N;i++){
		cin>>arr[i].h>>arr[i].w>>arr[i].s;
	}
	fill(dp,dp+(1<<maxN),-1);
	dp[0]=INF;
	for(long long i=0;i<(1<<N);i++){
		long long ch=0;
		long long tc=0;
		for(long long j=0;j<N;j++){
			if((i&(1<<j))>0){
				ch+=arr[j].h;
				tc++;
			}
		}
		//cout<<toBinary(i)<<" with "<<dp[i]<<'\n';
		for(long long j=0;j<N;j++){
			if((i&(1<<j))==0){
				dp[(i|(1<<j))]=max(dp[i|(1<<j)],min(arr[j].s,dp[i]-arr[j].w));
				if(ch+arr[j].h>=H){
					result=max(result,dp[(i|(1<<j))]);
					//if(dp[(i|(1<<j))]>=0) cout<<toBinary((i|(1<<j)))<<'\n';
				}
			}
		}
	}
	if(result==-1){
		cout<<"Mark is too tall"<<'\n';
	}else{
		cout<<result<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/