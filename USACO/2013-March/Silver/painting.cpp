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

#define maxN 50000

int N;
pair< pi , pi > arr[maxN];
unordered_set<int> visit;
int result=0;

//first is larger one
bool inside(pair< pi, pi > a, pair< pi, pi > b){
	if(a.first.first<b.first.first&&a.first.second<b.first.second&&a.second.first>b.second.first&&a.second.second>b.second.second) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("painting.in");
	ofstream cout("painting.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
	}
	sort(arr,arr+N);
	
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/