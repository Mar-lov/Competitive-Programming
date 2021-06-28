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

#define maxN 100005

struct Drone{
	long long x;
	long long v;
	long long index;
	long long left;
	long long right;

	bool alive;
};

long long toNext(Drone a){
	if(a.v<0) return a.left;
	return a.right;
}

long long N;
Drone arr[maxN];
priority_queue< pair<long double,ii> , vector< pair<long double,ii>  > , greater< pair<long double,ii> > > pq;

void update(long long i){
	long long ni=toNext(arr[i]);
	if(ni==0||ni==N+1||i==0||i==N+1) return;
	if(arr[ni].v==arr[i].v) return;
	long double t=(long double)(arr[i].x-arr[ni].x)/(long double)(arr[ni].v-arr[i].v);
	//cout<<"he:"<<t<<" "<<i<<" and "<<ni<<endl;
	if(t>0) pq.push(make_pair(t,make_pair(i,toNext(arr[i])) ) );
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>arr[i].x>>arr[i].v;
		arr[i].index=i;
		arr[i].alive=true;
		arr[i].left=i-1;
		arr[i].right=i+1;
	}
	//sort(arr,arr+N,cmpPos);
	for(long long i=1;i<=N;i++){
		update(i);
	}
	//update(3);

	while(!pq.empty()){
		long long tt=pq.top().first;
		long long ci=pq.top().second.first;
		long long ni=pq.top().second.second;
		pq.pop();
		//cout<<tt<<" "<<ci<<" and "<<ni<<endl;
		if(!(arr[ci].alive&&arr[ni].alive)) continue;
		
		arr[ci].alive=false;
		arr[ni].alive=false;
		if(arr[ci].index<arr[ni].index){
			arr[arr[ci].left].right=arr[ni].right;
			arr[arr[ni].right].left=arr[ci].left;
			update(arr[ci].left);
			update(arr[ni].right);
		}else{
			arr[arr[ni].left].right=arr[ci].right;
			arr[arr[ci].right].left=arr[ni].left;
			update(arr[ni].left);
			update(arr[ci].right);
		}
		
	}

	vector<long long> ans;
	for(long long i=1;i<=N;i++){
		if(arr[i].alive){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(long long a:ans){
		cout<<a<<" ";
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/