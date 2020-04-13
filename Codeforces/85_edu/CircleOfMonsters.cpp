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
typedef pair<int,int> pi;

ll a[300005];
ll b[300005];
ll ae[300005];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll tps=0;
		ll minc=100000000000000;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(i>0){
			ae[i]=a[i]-b[i-1];
			if(ae[i]<0) ae[i]=0;
			tps+=ae[i];
			minc=min(minc,a[i]-ae[i]);
			}

		}
			ae[0]=a[0]-b[n-1];
			if(ae[0]<0) ae[0]=0;
			tps+=ae[0];
			minc=min(minc,a[0]-ae[0]);

		cout<<minc+tps<<'\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/