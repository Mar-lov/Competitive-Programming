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

long long N,K;
long long arr[maxN];


long long solve(double x){
	long long tc=0;
	for(int i=0;i<N;i++){
		double a=arr[i]; 
		tc+=ll((sqrt(1 + 4*a/x)-1)/2);
	}
	//cout<<x<<": "<<tc<<'\n';
	return tc;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("tallbarn.in");
	ofstream cout("tallbarn.out");
	cin>>N>>K;
	for(long long i=0;i<N;i++){
		cin>>arr[i];
	}
	K-=N;
	double lo=0;
	double hi=1e18;
	while(hi-lo>=.000000001){
		double mid=(lo+hi)/2;
		//cout<<"bs:"<<mid<<'\n';
		if(solve(mid)>=K){
			lo=mid;
		}else{
			hi=mid;
		}
	}

	double result=0;
	long long tc=0;
	for(int i=0;i<N;i++){
		double a=arr[i];
		double nc=ll((sqrt(1 + 4*a/lo)-1)/2);
		tc+=nc;
		//cout<<i<<" "<<nc<<'\n';
		result+=a/(nc+1);
	}
	cout<<(ll)round(result-(K-tc)*lo)<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/