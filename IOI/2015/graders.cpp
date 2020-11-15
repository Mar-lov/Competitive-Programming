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

#define maxN 10000000

long long dpfront[maxN],dpback[maxN];

long long delivery(int N,int K,int L,int position[]){
	long long ci=0;
	while(position[ci]==0){
		ci++;
		N--;
	}
	long long pos[N];
	for(long long i=0;i<N;i++){
		pos[i]=position[i+ci];
		//cout<<i-ci<<" with "<<pos[i-ci]<<'\n';
	}
	for(long long i=0;i<N;i++){
		if(i<K) dpfront[i]=min((ll)L,2*pos[i]);
		else dpfront[i]=min((ll)L,2*pos[i])+dpfront[i-K];
	}
	for(long long i=0;i<N;i++){
		if(i<K) dpback[i]=min((ll)L,2*(L-pos[N-i-1]));
		else dpback[i]=min((ll)L,2*(L-pos[N-i-1]))+dpback[i-K];
	}
	/*
	for(long long i=0;i<N;i++){
		cout<<dpfront[i]<<" and "<<dpback[i]<<'\n';
	}
	*/
	long long result=min(dpback[N-1],dpfront[N-1]);
	for(long long i=1;i<=N-1;i++){
		//cout<<"This checks: "<<dpfront[i-1]<<" and "<<dpback[N-i-1]<<'\n';
		result=min(dpfront[i-1]+dpback[N-i-1],result);
	}
	return result;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/