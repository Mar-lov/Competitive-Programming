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




int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll> arr(n);
		ll tc=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			tc+=arr[i];
		}
		sort(arr.begin(),arr.end());
		bool found=false;
		for(int i=0;i<arr.size();i++){
			if(tc/(arr.size()-i)>=x){
				cout<<(arr.size()-i)<<'\n';
				found=true;
				break;
			}
			tc-=arr[i];
		}
		if(!found){
			cout<<0<<'\n';
		}
		
	}
	
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/