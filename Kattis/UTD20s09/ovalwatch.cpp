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
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int N,K;
vector<pair<int,int> > arr;

int main() {
	cin>>N>>K;
	int a,b;
	for(int i=0;i<K;i++){
		cin>>a>>b;
		arr.push_back(make_pair(b,a));
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<N;i++){
		int cp=i;
		for(int j=0;j<K;j++){
			if(arr[j].second==cp) cp=arr[j].second+1;
			else if(arr[j].second+1==cp) cp=arr[j].second;
		}
		cout<<cp<<" ";
	}
	cout<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/