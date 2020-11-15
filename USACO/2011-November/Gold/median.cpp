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

#define maxN 100005

int N,X;
int arr[maxN];
int psum[maxN];
long long result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("median.in");
	ofstream cout("median.out");
	cin>>N>>X;
	for(int i=1;i<=N;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=N;i++){
		if(arr[i]>=X) psum[i]++;
		psum[i]+=psum[i-1];
	}	
	vector<int> val;
	val.push_back(0);
	for(int i=1;i<=N;i++){
		int cv=2*psum[i]-i;
		//currently >-
		result+=(upper_bound(val.begin(),val.end(),cv)-val.begin());
		/*
		cout<<(upper_bound(val.begin(),val.end(),cv)-val.begin())<<":";
		cout<<cv<<":";
		for(int a:val){
			cout<<a<<" ";
		}
		cout<<'\n';
		*/
		val.push_back(cv);
		sort(val.begin(),val.end());
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/