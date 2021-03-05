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

#define INF 1000000000
#define maxN 100005

long long N;
long long arr[maxN];
vector<long long> gs;
long long lcfl[maxN];
long long lcfr[maxN];


bool visited[maxN];
long long css=0;

void dfs(long long n){
	if(visited[n]) return;
	css++;
	visited[n]=true;
	dfs(arr[n]);
}

long long gcd(long long a, long long b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

long long lcm(long long a,long long b){
	return (a*b)/gcd(a,b);
}

long long ansx=INF;
long long ansy=INF;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("robdan.in");
	ofstream cout("robdan.out");
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>arr[i];
	}
	for(long long i=1;i<=N;i++){
		if(!visited[i]){
			css=0;
			dfs(i);
			gs.push_back(css);
		}
	}

	fill(lcfl,lcfl+maxN,1);
	fill(lcfr,lcfr+maxN,1);

	long long cv=1;
	for(long long i=0;i<gs.size();i++){
		cv=lcm(cv,gs[i]);
		lcfl[i]=cv;
	}
	cv=1;
	for(long long i=gs.size()-1;i>=0;i--){
		cv=lcm(cv,gs[i]);
		lcfr[i]=cv;
	}
	ansx=lcfl[gs.size()-1];
	ansy=lcfl[gs.size()-1];
	for(long long i=0;i<gs.size();i++){
		if(gs[i]==0) continue;
		for(long long j=1;j<gs[i]-1;j++){
		ansy=min(ansy,lcm(lcm(gs[i]-j,j),lcm((i>0?lcfl[i-1]:1),(i<gs.size()-1?lcfr[i+1]:1))));
		}
		//ansy=min(ansy,nv);
	}
	cout<<ansy/gcd(ansx,ansy)<<" "<<ansx/gcd(ansx,ansy)<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/