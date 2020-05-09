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
typedef pair<ll,ll> pi;

#define MOD 1000000009

string s[2];

ll power(ll base,ll exp){
	if(exp==1) return base;
	long long save=power(base,exp/2);
	save*=save;
	save%=MOD;
	if(exp%2==1){
		save=(save)*(base%MOD);
	}
	return save%MOD;
}

ll hashF(ll which,ll start,ll len,ll base){
	ll val=0;
	for(ll i=0;i<len;i++){
		val+=power(base,i+1)*(s[which][start+i]-'a'+1);
		val%=MOD;
		//cout<<val<<'\n';
	}
	return val;
}
ll roll(ll which,ll start,ll len,ll val,ll base){
	val-=base*(s[which][start]-'a'+1);
	ll z=power(base,MOD-2);
	z%=MOD;
	return (((val%MOD)*z+power(base,len)*(s[which][start+len]-'a'+1))%MOD);
}

int main() {
	ifstream cin("censor.in");
	ofstream cout("censor.out");
	getline(cin,s[0]);
	getline(cin,s[1]);
	ll th1=hashF(1,0,s[1].length(),2);
	ll th2=hashF(1,0,s[1].length(),3);
	ll len=s[1].length();
	ll ci=0;
	ll sh1;
	ll sh2;
	bool rhn=true;
	while(ci+len<s[0].length()){
		if(rhn){
			sh1=hashF(0,ci,len,2);
			sh2=hashF(0,ci,len,3);
			rhn=false;
		}else{
			sh1=roll(0,ci,len,sh1,2);
			sh2=roll(0,ci,len,sh2,3);
			ci++;
		}
		//cout<<sh1<<" = "<<th1<<" : "<<sh2<<" = "<<th2<<'\n';
		if(sh1==th1&&sh2==th2){
			//cout<<"here:"<<ci<<" "<<len<<'\n';
			s[0].erase(s[0].begin()+ci,s[0].begin()+ci+len);
			rhn=true;
			ci=max((ll)0,ci-len);
		}
	}
	cout<<s[0]<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/