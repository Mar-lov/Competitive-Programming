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

#define maxN 100005

int N;
vector<int> arr;
vector<int> als;
vector<int> ans;

int main() {
	ifstream cin("sleepy.in");
	ofstream cout("sleepy.out");
	cin>>N;
	arr.resize(N);
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}

	int asv=N-2;
	als.push_back(arr[N-1]);
	while(asv>=0&&arr[asv]<=arr[asv+1]){
		als.push_back(arr[asv]);
		asv--;
	}
	reverse(als.begin(),als.end());

	for(int i=0;i<=asv;i++){
		int it=lower_bound(als.begin(),als.end(),arr[i])-als.begin();
		ans.push_back(it+(asv-i));
		als.insert(it+als.begin(),arr[i]);
	}

	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i<ans.size()-1) cout<<" ";
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/