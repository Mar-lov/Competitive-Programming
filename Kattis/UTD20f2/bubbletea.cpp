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

#define maxV 2000
#define INF 2000000000
long long N;
long long icost[maxV];
long long M;
long long tcost[maxV];
vector<long long> pt[maxV];
long long tc=0;
long long mtc=INF;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>icost[i];
	}
	cin>>M;
	for(long long i=0;i<M;i++){
		cin>>tcost[i];
	}
	for(long long i=0;i<N;i++){
		long long am=0;
		cin>>am;
		for(long long j=0;j<am;j++){
			long long cv;
			cin>>cv;
			cv--;
			pt[i].push_back(cv);	
		}
	}
	cin>>tc;
	for(long long i=0;i<N;i++){
		for(long long j=0;j<pt[i].size();j++){
			mtc=min(mtc,icost[i]+tcost[pt[i][j]]);
		}
	}
	if((tc/mtc)<=1) cout<<0<<'\n';
	else cout<<(tc/mtc)-1<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/