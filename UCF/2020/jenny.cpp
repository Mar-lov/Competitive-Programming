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

long long T;
long long D,I;
long long at[10];
long long ts=0;
bool found=false;
bool isPrime(long long n){
	if(n==1) return false;
	if(n==0) return false;
	if(n%2==0) return false;
	for(long long i=3;i<=sqrt(n);i+=2){
		if(n%i==0) return false;
	}
	return true;
}

void build(long long s){
	if(found) return;
	if(s==-1){
		long long cn=0;
		for(long long i=0;i<10;i++){
			if(at[i]!=-1){
				cn+=i*pow(10,at[i]);
			}
		}
		if(isPrime(cn)&&cn+2<pow(10,D)&&isPrime(cn+2)){
			//cout<<cn<<'\n';
			ts++;
			if(ts==I){
				cout<<cn<<'\n';
				found=true;
			}
		}
		return;
	}
	for(long long i=0;i<10;i++){
		if(s==D-1&&i==0) continue;
		if(at[i]==-1){
			at[i]=s;
			build(s-1);
			at[i]=-1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	for(long long k=0;k<T;k++){
		cin>>D>>I;
		if(D>10){
			cout<<"Brice doesn't stand a chance!"<<'\n';
			continue;
		}
		found=false;
		fill(at,at+10,-1);
		//cout<<"VAL:"<<k<<'\n';
		build(D-1);
		if(!found){
			cout<<"Brice doesn't stand a chance!"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/