/*
Code by @marlov       
*/
#include <iostream>
#include <fstream>
#include <string>
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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define maxN 100005

ll N;
ll arr[2*maxN];
ll result=maxN*(ll)maxN;

ll inversions(ll a,ll b){
	ll t=0;
	ll c1=0;
	for(ll i=a;i<b;i++){
		if(arr[i]==1) c1++;
		else t+=c1;
	}
	return t;
}

ll absv(long long v){
	if(v<0) return -v;
	return v;
}

int main() {
	//ifstream cin("balance.in");
	//ofstream cout("balance.out");
	cin>>N;
	for(ll i=0;i<2*N;i++){
		cin>>arr[i];
	}
	ll invf=inversions(0,N);
	ll invs=inversions(N,2*N);
	ll dif=invf-invs;
	ll mv=1;
	if(dif>0) mv=0;
	ll nf=0;
	ll ns=0;
	for(ll i=0;i<N;i++){
		if(arr[i]==mv) nf++;
		if(arr[i+N]!=mv) ns++;
	}
	ll fp=N;
	ll sp=N-1;
	ll cost=0;
	while(fp>=0&&sp<2*N){
		fp--;
		sp++;
		while(fp>=0&&arr[fp]==mv) fp--;
		while(sp<2*N&&arr[sp]!=mv) sp++;
		if(fp<0||sp>=2*N) continue;
		cost+=(N-1-fp)+(sp-N);
		cost++;
		invf-=nf;
		invs-=ns;
		dif=invf-invs;
		result=min(result,cost+absv(dif));

	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/