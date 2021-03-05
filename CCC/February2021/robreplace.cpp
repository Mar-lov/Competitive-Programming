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

#define maxN 1000005
#define maxB 17

long long N,X,K;
long long arr[maxN];
long long psum[maxN];
long long rl[maxN];
long long sum(long long a,long long b){
	return psum[b]-psum[a-1];
}

bool solve(long long len){
	multiset<long long> mvs;
	//cout<<len<<" ";
	for(long long i=1;i+K-1<=len;i++){
		mvs.insert(rl[i]);
		//cout<<rl[i]<<" ";
	}
	//cout<<endl;
	for(long long i=1;i+len-1<=N;i++){
		long long csum=sum(i,i+len-1);
		if(i>1) mvs.erase(mvs.find(rl[i-1]));
		mvs.insert(rl[(i+len-1)-(K-1)]);
		long long mrl=*mvs.rbegin();//maximum raft location
		if(csum-mrl<=X) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("robreplace.in");
	ofstream cout("robreplace.out");
	cin>>N>>X>>K;
	for(long long i=1;i<=N;i++){
		cin>>arr[i];
	}
	for(long long i=1;i<=N;i++){
		psum[i]+=psum[i-1]+arr[i];
	}

	long long ctv=0;
	for(long long i=1;i+K-1<=N;i++){
		if(i==1){
			ctv=sum(0,K-1);
		}
		ctv-=arr[i-1];
		ctv+=arr[i+K-1];
		rl[i]=ctv;
	}

	long long a=K;
	long long b=N;
	while(a<b){
		long long mid=(a+b+1)/2;
		if(solve(mid)){
			a=mid;
		}else{
			b=mid-1;
		}
	}
	cout<<a<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/