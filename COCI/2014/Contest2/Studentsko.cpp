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

#define maxN 5005

int N,K;
pi gl[maxN];
int arr[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>gl[i].first;
		gl[i].second=i;
	}

	sort(gl,gl+N);

	for(int i=0;i<N;i++){
		arr[gl[i].second]=i/K;
	}
	vector<int> ls;
	for(int i=0;i<N;i++){
		int cv=arr[i];
		if(ls.empty()||cv>=ls.back()){
			ls.push_back(cv);
		}else{
			*upper_bound(ls.begin(),ls.end(),cv)=cv;
		}
	}
	cout<<N-ls.size()<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/