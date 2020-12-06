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

#define maxN 40005
#define maxD 50005
#define maxP 17

long long N,D;
long long arr[maxN];
long long day[maxD][2];
long long result=0;

long long ps[(1<<maxP)];
long long pp[(1<<maxP)];
long long sp[(1<<maxP)];
long long ss[(1<<maxP)];


void update(long long index){
	long long lc=index*2;
	long long rc=(index*2)+1;
	pp[index]=max(ps[lc]+sp[rc],max(pp[lc]+sp[rc],ps[lc]+pp[rc]));
	ps[index]=max(pp[lc]+ss[rc],max(ps[lc]+ss[rc],ps[lc]+ps[rc]));
	sp[index]=max(ss[lc]+pp[rc],max(sp[lc]+sp[rc],ss[lc]+sp[rc]));
	ss[index]=max(ss[lc]+ss[rc],max(sp[lc]+ss[rc],ss[lc]+ps[rc]));
}


void solve(long long index){
	update(index);
	if(index!=1) solve(index/2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("optmilk.in");
	ofstream cout("optmilk.out");
	cin>>N>>D;
	for(long long i=0;i<N;i++){
		cin>>arr[i];
		pp[(1<<(maxP-1))+i]=arr[i];
	}
	for(long long i=0;i<D;i++){
		cin>>day[i][0]>>day[i][1];
		day[i][0]--;
	}
	for(long long i=0;i<N;i++){
		solve(((1<<(maxP-1))+i)/2);
	}
	/*
	for(long long i=0;i<(1<<maxP);i++){
		cout<<i<<": "<<pp[i]<<'\n';
	}
	*/
	//cout<<"long longial: "<<max(max(sp[1],ps[1]),max(pp[1],ss[1]))<<'\n';
	for(long long i=0;i<D;i++){
		long long ci=(1<<(maxP-1))+day[i][0];
		//cout<<ci<<'\n';
		pp[ci]=day[i][1];
		solve((ci)/2);
		//cout<<max(max(sp[1],ps[1]),max(pp[1],ss[1]))<<'\n';
		result+=max(max(sp[1],ps[1]),max(pp[1],ss[1]));
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/