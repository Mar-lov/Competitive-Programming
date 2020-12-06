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

int N;
pair<int,int> arr[maxN];
int ts=0;
bool solved[maxN];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("trapped.in");
	ofstream cout("trapped.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i].second>>arr[i].first;
	}
	sort(arr,arr+N);
	for(int i=0;i<N-1;i++){
		int lo=i;
		int hi=i+1;
		int val=arr[i+1].first-arr[i].first;
		while(lo>=0&&hi<N&&(val>arr[lo].second||val>arr[hi].second)&&!solved[lo]){
			 if(val>arr[lo].second){
				 lo--;
				 if(lo>=0) val+=(arr[lo+1].first-arr[lo].first);
			 }
			 if(val>arr[hi].second){
				 hi++;
				if(hi<N) val+=(arr[hi].first-arr[hi-1].first);
			 }
		}
		if(lo==-1||hi==N||solved[lo]){
			solved[i]=true;
			ts+=(arr[i+1].first-arr[i].first);
		}
	}
	cout<<(arr[N-1].first-arr[0].first)-ts<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/