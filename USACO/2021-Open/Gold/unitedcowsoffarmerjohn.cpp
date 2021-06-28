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

#define maxN 200005

long long N;
long long arr[maxN];
vector<long long> breed[maxN];
long long pv[maxN];
long long result=0;

long long ft[maxN];
void update(long long x, long long v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
long long query (long long x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>arr[i];
		//cout<<arr[i]<<endl;
		if(breed[arr[i]].size()>0){
			pv[i]=breed[arr[i]].back();
		}
		breed[arr[i]].push_back(i);
	}
	for(long long i=1;i<=N;i++){
		if(pv[i]!=0) update(pv[i],-1);
		result+=query(i)-(pv[i]==0?0:query(pv[i]));
		update(i,1);		
	}
	cout<<result<<'\n';
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/