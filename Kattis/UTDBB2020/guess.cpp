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
typedef pair<int,int> pi;



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a=1;
	int b=1000;
	while(a<b){
		int mid=(a+b)/2;
		cout<<mid<<endl;
		string s;
		cin>>s;
		if(s=="lower"){
			b=mid-1;
		}else if(s=="higher"){
			a=mid+1;
		}else if(s=="correct"){
			return 0;
		}
	}
	cout<<a<<'\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/