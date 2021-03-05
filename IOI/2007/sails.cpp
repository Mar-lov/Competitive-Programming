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

#define maxV 100005
#define INF 1000000000

long long N;
long long H[maxV];
long long K[maxV];
long long maxH=0;
long long ts[maxV];
long long result=INF;

void solve(long long n){
	if(n==N){
		long long cv=0;
		/*
		for(long long i=0;i<maxH;i++){
			cout<<ts[i]<<" ";
		}
		cout<<'\n';
		*/
		for(long long i=0;i<maxH;i++){

			cv+=((ts[i])*(ts[i]-1))/2;
		}
		//cout<<"pv:"<<cv<<'\n';
		result=min(result,cv);
		return;
	}
	long long cl[H[n]];
	for(long long i=0;i<H[n]-K[n];i++){
		cl[i]=0;
	}
	for(long long i=H[n]-K[n];i<H[n];i++){
		cl[i]=1;
	}
	do{
		for(long long i=0;i<H[n];i++){
			if(cl[i]==1) ts[i]++;
		}
		solve(n+1);
		for(long long i=0;i<H[n];i++){
			if(cl[i]==1) ts[i]--;
		}
	}while(next_permutation(cl,cl+H[n]));
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>H[i]>>K[i];
		maxH=max(maxH,H[i]);
	}
	solve(0);
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/