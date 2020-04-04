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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;



int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cur;
		 int lc[n+1];
		for(int i=0;i<n;i++){
			cin>>cur;
			lc[cur]=i;
		}
		int cv=1;
		while(cv<n&&lc[cv+1]>lc[cv]){
			cv++;
		}
		cout<<n-cv<<'\n';


	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/