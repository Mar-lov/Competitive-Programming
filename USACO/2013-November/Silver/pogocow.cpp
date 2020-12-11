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

long long N;
pi arr[maxN];
vector< pair< long long,pair<long long,long long> > > vals;
long long dp[maxN];
long long result=0;

bool cmp( pair<long long,pair<long long,long long> > a, pair<long long,pair<long long,long long> > b){
	if(a.first==b.first) return a.second.second<b.second.second;
	return a.first<b.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("pogocow.in");
	ofstream cout("pogocow.out");
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+N);
	for(long long i=0;i<N;i++){
		dp[i]=arr[i].second;	
	}
	for(long long i=0;i<N;i++){
		for(long long j=i+1;j<N;j++){
			vals.push_back(make_pair(arr[j].first-arr[i].first,make_pair(i,j)));
		}
	}
	sort(vals.begin(),vals.end(),cmp);
	for(long long k=0;k<vals.size();k++){
		pair<long long, pair<long long,long long> > cur=vals[k];
		dp[cur.second.second]=max(dp[cur.second.second],dp[cur.second.first]+arr[cur.second.second].second);
		result=max(dp[cur.second.second],result);
	}
	for(long long i=0;i<N;i++){
		result=max(result,dp[i]);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/