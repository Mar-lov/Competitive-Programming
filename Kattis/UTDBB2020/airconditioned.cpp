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

#define maxN 105

int N;
pi arr[maxN];

bool cmp(pi a,pi b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	int a,b;
	for(int i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr,arr+N,cmp);
	int result=1;
	int farright=arr[0].second;
	for(int i=1;i<N;i++){
		if(arr[i].first>farright){
			result++;
			farright=arr[i].second;
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/