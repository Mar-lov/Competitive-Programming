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
		int n,x;
		cin>>n>>x;
		set<int> place;
		int cur;
		for(int i=0;i<n;i++){
			cin>>cur;
			place.insert(cur);
		}
		int cv=0;
		int cp=0;
		for(set<int>::iterator it=place.begin();it!=place.end();++it){
			if(x-(*it-cv-1)>=0){
				x-=*it-cv-1;
				cv=*it;
				cp=*it;
				//cout<<*it<<'\n';
			}else{
				break;
			}
		}
		cout<<cp+x<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/