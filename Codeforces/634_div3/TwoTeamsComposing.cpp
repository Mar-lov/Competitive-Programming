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


int nv[200005];

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		fill(nv,nv+200005,0);
		int mcv=0;
		int tdv=0;
		int cur;
		for(int i=0;i<n;i++){
			cin>>cur;
			if(nv[cur]==0){
				tdv++;
			}
			nv[cur]++;
			mcv=max(mcv,nv[cur]);
		}
		//cout<<mcv<<" "<<tdv<<'\n';
		if(mcv>tdv){
			cout<<tdv<<'\n';
		}else if(mcv==tdv){
			cout<<tdv-1<<'\n';
		}else if(mcv<tdv){
			cout<<mcv<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/