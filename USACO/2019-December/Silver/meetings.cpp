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
typedef pair<long long,long long> pi;

#define maxN 50005

struct cow{
	long long w,x,d;
};

long long N,L;
long long tw=0;
cow arr[maxN];
long long wo[maxN];
vector<pi> nxt;
long long result=0;
vector<int> lv;
vector<int> rv;

bool cmpx(cow a,cow b){
	return a.x<b.x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("meetings.in");
	ofstream cout("meetings.out");

	cin>>N>>L;
	//L*=2;
	for(long long i=0;i<N;i++){
		cin>>arr[i].w>>arr[i].x>>arr[i].d;
		//arr[i].x*=2;
		tw+=arr[i].w;
	}
	sort(arr,arr+N,cmpx);
	for(long long i=0;i<N;i++){
		wo[i]=arr[i].w;
		if(arr[i].d==1){
			rv.push_back(arr[i].x);
			nxt.push_back(make_pair(L-arr[i].x,1));
		}else{
			lv.push_back(arr[i].x);
			nxt.push_back(make_pair(arr[i].x,-1));
		}

	}
	sort(nxt.begin(),nxt.end());
	long long pl=0;
	long long pr=N-1;
	long long ct=0;
	long long tt=0;
	long long ci=0;
	while((double)ct<(double)(tw/2.0)){
		if(nxt[ci].second==1){
			ct+=wo[pr];
			pr--;
		}else{
			ct+=wo[pl];
			pl++;
		}
		tt=nxt[ci].first;
		ci++;
	}
	for(int a:rv){
		result+=lower_bound(lv.begin(),lv.end(),a+2*tt+1)-lower_bound(lv.begin(),lv.end(),a);
		/*
		for(int b:lv){
			if(a<=b&&b<=a+2*tt){
				result++;
			}
		}
		*/
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/