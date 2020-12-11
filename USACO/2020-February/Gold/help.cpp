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

#define maxN 100005
#define MOD 1000000007

long long N;
pi arr[maxN];
long long pends[2*maxN];
int last[2*maxN];
long long dp[maxN];

bool cmp(pi a,pi b){
	//possible error
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}

long long add(long long a,long long b){
	return (a+b)%MOD;
}

long long sub(long long a,long long b){
	a=a-b;
	while(a<0) a+=MOD;
	return a;
}

long long Power(long long base,long long exp){
	if(exp==1) return base;
	if(exp==0) return 1;
	long long save=Power(base,exp/2);
	save*=save;
	save%=MOD;
	if(exp%2==1){
		save*=base;
	}
	return save%MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ifstream cin("help.in");
	//ofstream cout("help.out");
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>arr[i].first>>arr[i].second;
		pends[arr[i].second]++;
	}
	for(int i=1;i<=2*N;i++){
		pends[i]+=pends[i-1];
	}
	sort(arr+1,arr+N+1,cmp);
	int ci=0;
	for(int i=0;i<=2*N;i++){
		last[i]=ci;
		while(ci<=N&&arr[ci+1].second==i) ci++;
		//cout<<i<<": "<<last[i]<<'\n';
	}
	dp[0]=0;
	for(long long i=1;i<=N;i++){
		//don't contain
		dp[i]=add(dp[i],dp[i-1]);
		cout<<i<<" dont contain "<<dp[i]<<'\n';
		//contain outside
		dp[i]=add(dp[i],dp[last[arr[i].first]]+Power(2,last[arr[i].first])-1);
		cout<<dp[last[arr[i].first]]+Power(2,last[arr[i].first])-1<<'\n';
		cout<<i<<" contain outside "<<dp[i]<<'\n';
		//contain but inside
		dp[i]=add(dp[i],Power(2,pends[arr[i].second]-pends[arr[i].first-1]-1));
		cout<<i<<" contain inside "<<dp[i]<<'\n';

	}
	/*
	for(long long i=0;i<=N;i++){
		cout<<dp[i]<<" ";
	}
	cout<<'\n';
	*/
	cout<<dp[N]<<'\n';
	return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/