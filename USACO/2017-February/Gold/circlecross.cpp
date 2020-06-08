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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 50002
int T;
int N, ft[100013];
pair<int,int> loc[maxN];
int result=0;
void update(int x, int v) {
	while(x<=N){
		 ft[x]+=v;
		 x+=(x&-x);
	}
}
int query (int x) { 
	return (x>0 ? (ft[x]+query(x-(x&-x))):0);
}
int main() {
	ifstream cin("circlecross.in");
	ofstream cout("circlecross.out");
	cin>>T;
	N=2*T;
	fill(loc,loc+maxN,make_pair(-1,-1));
	int cur;
	for(int i=0;i<2*T;i++){
		cin>>cur;
		cur--;
		if(loc[cur].first==-1){
			loc[cur].first=i+1;
		}else{
			loc[cur].second=i+1;
		}
		//cout<<"val at "<<i<<" is "<<cur<<'\n';
	}
	sort(loc,loc+T);
	for(int i=0;i<T;i++){
		result+=query(loc[i].second)-query(loc[i].first);
		//cout<<"it gets:"<<query(loc[i].second)<<" "<<query(loc[i].first)<<'\n';
		update(loc[i].second,1);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/