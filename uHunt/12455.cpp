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




int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p;
		cin>>p;
		int l[p];
		for(int i=0;i<p;i++){
			cin>>l[i];
		}
		bool pos=false;
		for(int i=0;i<pow(2,p)&&!pos;i++){
			int cs=0;
			for(int j=0;j<p;j++){
				if((i&(1<<j))>0) cs+=l[j];
			}
			if(cs==n) pos=true;
		}
		if(pos){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/