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

#define maxN 1000005
#define MOD (ll)1000000009
#define BASE (ll)2
long long t;
long long psum[maxN];
long long divq[maxN];
ll power(ll base,ll exp){
	if(exp==0) return 1;
	if(exp==1) return base;
	ll save=power(base,exp/2);
	save*=save;
	save%=MOD;
	if(exp%2==1) save*=base;
	return save%MOD;
}

//most likey dp from one side that check with the other. For answer loop through all dps and connect
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	cin.ignore();
	string s;
	long long N;
	divq[0]=1;
	for(int i=1;i<maxN;i++){
		divq[i]=(divq[i-1]*power(BASE,MOD-2))%MOD;
	}
	while(t--){
		long long ans=0;
		getline(cin,s);
		N=s.length();
		psum[0]=0;
		for(long long i=1;i<=N;i++){
			psum[i]=0;
			psum[i]+=(s[i-1]-'a'+1)*power(BASE,i);
			psum[i]%=MOD;
			psum[i]+=psum[i-1];
		}
		long long ci=0;
		//rewrite this whole thing
		//((psum[ci+len+1]-psum[ci])*div(ci))%MOD==((psum[N-ci]-psum[N-ci-len-1])*div(N-ci-len-1))%MOD
		while(ci<((N+1)/2)){
			for(int len=0;len+ci<=N;len++){
				//cout<<ci<<" "<<len<<" "<<((psum[ci+len+1]-psum[ci]+MOD)*div(ci))%MOD<<" === "<<((psum[N-ci]-psum[N-ci-len-1]+MOD)*div(N-ci-len-1))%MOD<<'\n';
				if(((psum[ci+len+1]-psum[ci]+MOD)*divq[ci])%MOD==((psum[N-ci]-psum[N-ci-len-1]+MOD)*divq[N-ci-len-1])%MOD){
					//cout<<ci<<" "<<len<<" "<<ci+len+1<<" "<<N-ci<<'\n';
				
					if(ci+len+1==N-ci){
						ans++;
					}else{
						ans+=2;
					}
					ci+=len;
					break;
				}
			}
			ci++;
		}
		cout<<ans<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/
