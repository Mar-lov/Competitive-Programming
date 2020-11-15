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

int N,K;
int arr[maxN];
int ans=1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("lineup.in");
	ofstream cout("lineup.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	unordered_set<int> cnts;
	unordered_map<int,int> hm;
	int f=0;
	int s=0;
	while(f<N){
		if(cnts.size()>K+1||s==N){
			hm[arr[f]]--;
			if(hm[arr[f]]==0){
				cnts.erase(arr[f]);
			}
			f++;
		}else{
			cnts.insert(arr[s]);
			hm[arr[s]]++;
			ans=max(ans,hm[arr[s]]);
			s++;
		}
	}
	cout<<ans<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/