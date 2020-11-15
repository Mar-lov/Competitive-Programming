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
 
#define maxV 1000002
#define MOD 1000000007
//const long long MOD=1000000007;
long long N,M,K;
long long sum=0;
unordered_set<long long> cols;
unordered_set<long long> rows;
long long cm[maxV];
long long rm[maxV];
 
long long power(long long base,long long exp){
	if(exp==1) return base;
	long long save=power(base,exp/2);
	save*=save;
	save%=MOD;
	if(exp%2==1) save*=base;
	return save%MOD;
}

long long add(long long a,long long b){
	a+=b;
	while(a<0) a+=MOD;
	return a%MOD;
}
long long sub(long long a,long long b){
	a-=b;
	while(a<0) a+=MOD;
	return a%MOD;
}
long long mult(long long a,long long b){
	a*=b;
	return a%MOD;
}

long long qsum(long long T,long long s,long long e){
	T%=MOD;
	s%=MOD;
	e%=MOD;
	//if(T%2==0) return mult(T*power(2,MOD-2),add(s,e));
	return mult(T,mult(add(s,e),power(2,MOD-2)));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	fill(cm,cm+maxV,1);
	fill(rm,rm+maxV,1);
	char c;
	long long x,m;
	for(long long i=0;i<K;i++){
		cin>>c>>x>>m;
		x--;
		if(c=='R'){
			rows.insert(x);
			rm[x]=mult(rm[x],m);
		}else if(c=='S'){
			cols.insert(x);
			cm[x]=mult(cm[x],m);
		}
	}
	for(long long i=0;i<N;i++){
		sum=add( sum , mult(rm[i],(qsum(M,mult(i,M)+1,mult(i,M)+M))) );
	}
	for(long long i=0;i<M;i++){
		sum=add(sum, mult(sub(cm[i],1),(qsum(N,i+1,mult(N-1,M)+i+1))) );
	}
	for(long long i:cols){
		for(long long j:rows){
			long long cv=add(mult(M,j),i+1);
			sum=sub(sum,mult(add(sub(cm[i],1),rm[j]),cv) );
			sum=add(sum, mult( mult(cm[i],rm[j]), cv) );
		}
	}
	cout<<sum<<'\n';
    return 0;
}
 
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/