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


#define maxN 1000002
#define MOD 1000000007
#define base 5

string s,t;
string n;
ll th=0;
ll h[maxN];

ll power(ll b,ll p){
	if(p==1) return b;
	ll save=power(b,p/2);
	save*=save;
	if(p%2==1) save*=b;
	return save%MOD;
}

int main() {
	ifstream cin("censor.in");
	ofstream cout("censor.out");
	getline(cin,s);
	getline(cin,t);
	ll i=0;
	ll j=0;
	for(ll i=0;i<t.length();i++){
		th+=power(base,i+1)*(t[i]-'a'+1);
		th%=MOD;
	}
	while(i<s.length()){
		n.insert(n.end(),s[i]);
		j++;
		if(n.length()<=t.length()){
			h[j]=h[j-1]+power(base,j)*(n.back()-'a'+1);
			h[j]%=MOD;
			if(n.length()==t.length()&&h[j]==th){
				j-=t.length();
				for(ll i=0;i<t.length();i++){
					n.pop_back();
				}
			}
		}else{
			h[j]=h[j-1];
			//cout<<n[j-t.length()-1]-'a'+1<<" : "<<base*(n[j-t.length()-1]-'a'+1)<<'\n';
			h[j]-=base*(n[j-t.length()-1]-'a'+1);
			ll z=power(base,MOD-2);
			h[j]*=z;
			h[j]%=MOD;
			h[j]+=power(base,t.length())*(n.back()-'a'+1);
			h[j]%=MOD;
			if(h[j]==th){
				j-=t.length();
				for(ll i=0;i<t.length();i++){
					n.pop_back();
				}
			}
		}
		//cout<<h[j]<<" : "<<n<<'\n';
		i++;
	}
	cout<<n<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/