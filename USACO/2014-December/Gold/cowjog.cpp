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

long long N,T;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("cowjog.in");
	ofstream cout("cowjog.out");
	cin>>N>>T;
	long long p,s;
	vector<long long> tl;
	for(long long i=0;i<N;i++){
		cin>>p>>s;
		p=-(p+s*T);
		if(tl.empty()||p>=tl.back()){
			tl.push_back(p);
		}else{
			*(upper_bound(tl.begin(),tl.end(),p))=p;
		}
	}	
	cout<<tl.size()<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/