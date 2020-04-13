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
		int N;
		cin>>N;
		int p,c;
		int mp=0;
		int mc=0;
		bool pos=true;
		for(int i=0;i<N;i++){
			 cin>>p>>c;
			 if(p<mp||c<mc||c>p||(mp==p&&c>mc)){
				 pos=false;
			 }
			 mp=p;
			 mc=c;
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