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

#define maxN 1100005

long long N;
long long arr[maxN];
long long L[maxN];
long long R[maxN];
vector< pair<long long,long long> > result;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	fill(L,L+maxN,0);
	fill(R,R+maxN,N+1);
	for(long long i=1;i<=N;i++){
		cin>>arr[i];
	}
	//calculate L
	vector<long long> pv;
	for(long long i=1;i<=N;i++){
		while(pv.size()>0&&arr[pv.back()]<arr[i]) pv.pop_back();
		if(pv.size()>0) L[i]=pv.back();
		pv.push_back(i);
	}
	//calculate R
	pv.clear();
	for(long long i=N;i>0;i--){
		while(pv.size()>0&&arr[pv.back()]>arr[i]) pv.pop_back();
		if(pv.size()>0) R[i]=pv.back();
		pv.push_back(i);
	}

	vector<ii> pq;

	long long ci=1;
	while(ci<=N){
		while(pq.size()>0&&(pq.back()).first<=ci) pq.pop_back();
		for(auto a:pq){
			if(L[ci]>=a.second) break;
			if(ci-a.second!=arr[ci]-arr[a.second]) continue;
			result.push_back(make_pair(a.second,ci));
			pq.clear();
			break;
		}
		pq.push_back(make_pair(R[ci],ci));
		ci++;
	}

	cout<<result.size()<<"\n";
	for(auto a:result){
		cout<<a.first<<" "<<a.second<<"\n";
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/