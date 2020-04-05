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
		vector<pi> ans;
		int n;
		cin>>n;
		int vals[n];
		int has[n];
		fill(has,has+n,0);
		for(int i=0;i<n;i++){
			cin>>vals[i];
			has[vals[i]]++;
		}
		bool pos=true;
		int ml=0;
		int cmv=2;
		for(int i=1;i<n;i++){
			cmv=min(cmv,has[i]);
			if(cmv<has[i]) pos=false;
			if(has[i]==2) ml=i;
		}
		if(ml==0) pos=false;
		if(pos){
			set<int> cnts;
			//left
			bool lp=true;
			for(int i=0;i<ml;i++){
				if(cnts.count(vals[i])>0||vals[i]>ml) lp=false;
					else cnts.insert(vals[i]);
			}
			if(lp) ans.push_back({ml,n-ml});
			//right
			cnts.clear();
			bool rp=true;
			for(int i=n-1;i>n-1-ml;i--){
				if(cnts.count(vals[i])>0||vals[i]>ml) rp=false;
					else cnts.insert(vals[i]);
			}
			if(rp&&n-ml!=ml) ans.push_back({n-ml,ml});
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<'\n';
		}

	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/