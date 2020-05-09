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
int bottom[maxN];
vector<int> items[maxN];

int main() {
	ifstream cin("dishes.in");
	ofstream cout("dishes.out");
	cin>>N;
	int mp=0;
	int ans=0;
	int x;
	for(int i=0;i<N;i++){
		cin>>x;
		if(x<mp){
			ans=i;
			break;
		}
		for(int i=x;i>0&&bottom[i]==0;i--){
			bottom[i]=x;
		}
		while(!items[bottom[x]].empty()&&items[bottom[x]].back()<x){
			mp=items[bottom[x]].back();
			items[bottom[x]].pop_back();
		}
		items[bottom[x]].push_back(x);
	}

	cout<<ans<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/