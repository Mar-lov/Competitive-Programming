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
typedef pair<int,int> pi;

	int N,M;
	ll len[100005];
	ll psum[100005];
	ll tlen=0;

int main() {
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>len[i];
		tlen+=len[i];
	}
	for(int i=M-1;i>=0;i--){
		psum[i]=psum[i+1]+len[i];
	}
	if(tlen<N){
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<M;i++){
		if(i+len[i]>N){
			cout<<"-1";
			return 0;
		}
	}
	for(int i=0;i<M;i++){
		cout<<max((ll)i+1,N-psum[i]+1)<<" ";
	}
	cout<<'\n';

	



    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/