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

int D;

int ms(int N,int sl,int el){
	return min(abs(el-sl),N-abs(el-sl));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>D;
	for(int d=1;d<=D;d++){
		int N,P,S;
		cin>>N>>P>>S;
		map<double,int> to;
		double cv;
		for(int i=0;i<N;i++){
			cin>>cv;
			to[cv]=i;
		}
		double ps[P];
		for(int i=0;i<P;i++){
			cin>>ps[i];
		}
		double s,e;
		int md=10000;
		cout<<"Day #"<<d<<":\n";
		for(int i=0;i<S;i++){
			cin>>s>>e;
			int sl=to[s];
			int el=to[e];
			md=ms(N,sl,el);
			for(int i=0;i<P;i++){
				md=min(md,1+ms(N,to[ps[i]],el));
			}
			cout<<md<<'\n';
		}
		cout<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/