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

#define maxN 100005

ll N;
ll arr[maxN];
ll ans=0;

long long sumn2(long long n){
	return (n*(n+1)*(2*n+1))/6;
}

int main() {
	ifstream cin("cbarn.in");
	ofstream cout("cbarn.out");
	cin>>N;
	ll c=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		c=max(0ll,c+arr[i]-1);
	}
	for(int i=0;i<N;i++){
		if(c==0){
			rotate(arr,arr+i,arr+N);
			break;
		}
		c=max(0ll,c+arr[i]-1);
	}
	/*
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	*/
	for(int i=0;i<N;i++){
		ans+=sumn2(arr[i]+c-1)-sumn2(c-1);
		c=max(0ll,c+arr[i]-1);
	}
	cout<<ans<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/