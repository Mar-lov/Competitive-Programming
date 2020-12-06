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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		long long N,K;
		cin>>N>>K;
		long long s[N];
		long long p[K];
		long long ta[N];
		fill(ta,ta+N,0);
		long long cs=0;
		
		//cout<<"ta:";
		for(long long i=0;i<N;i++){
			cin>>s[i];
			cs+=s[i];
			if(s[i]>0){
				ta[i]++;
			}else{
				ta[i]--;
			}
			if(i>0) ta[i]+=ta[i-1];
			//cout<<ta[i]<<" ";
		}
		//cout<<endl;
		for(long long i=0;i<K;i++){
			cin>>p[i];
			
			if(ta[p[i]-1]>0){
				cs+=ta[p[i]-1];
			}
		}
		cout<<cs<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/