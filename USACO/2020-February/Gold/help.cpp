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
pair<long long,long long> arr[maxN];
long long psum[maxN*2];
long long pow2[maxN];
long long result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("help.in");
	ofstream cout("help.out");
	pow2[0]=1;
	for(long long i=1;i<maxN;i++){
		pow2[i]=(2*pow2[i-1])%MOD;
	}
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
		psum[arr[i].first]++;
		psum[arr[i].second]--;
	}

	for(long long i=1;i<=2*N;i++){
		psum[i]+=psum[i-1];
	}
	sort(arr,arr+N);
	for(long long i=0;i<N;i++){
		result+=(pow2[N-1-(psum[arr[i].first-1])])%MOD;
		result%=MOD;
	}
	cout<<result<<'\n';
	return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/