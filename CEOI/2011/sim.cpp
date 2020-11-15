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

string p,t;
long long sim=0;
vector<int> letters[26];
int pb[26][2];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>p>>t;
	for(int i=0;i<t.length();i++){
		letters[(t[i]-'a')].push_back(i);
	}
	for(int i=0;i<p.length();i++){
		int ci=p[i]-'a';
		int ub=upper_bound(letters[ci].begin()+pb[ci][1],letters[ci].end(),t.length()-(p.length()-i-1)-1)-letters[ci].begin();
		int lb=lower_bound(letters[ci].begin()+pb[ci][0],letters[ci].end(),i)-letters[ci].begin();
		//cout<<p[i]<<" at "<<i<<" from "<<lb<<" to "<<ub<<'\n';
		pb[ci][0]=lb;
		pb[ci][1]=ub;
		sim+=ub-lb;
	}
	cout<<sim<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/