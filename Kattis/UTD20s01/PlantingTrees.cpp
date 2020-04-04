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

int N;
vector<int> t;
int maxt=-1;

int main() {
	cin>>N;
	int cur;
	for(int i=0;i<N;i++){
		cin>>cur;
		t.push_back(cur);
	}
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	for(int i=0;i<t.size();i++){
		maxt=max(maxt,t[i]+i+2);
	}
	cout<<maxt<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/