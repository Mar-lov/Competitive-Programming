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
	string s;
	getline(cin,s);
	while(s!="END"){
		if(s=="1") cout<<1<<'\n';
		else if(s.length()==1) cout<<2<<'\n';
		else if(s.length()<10) cout<<3<<'\n';
		else if(s.length()>=10) cout<<4<<'\n';
		getline(cin,s);
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/