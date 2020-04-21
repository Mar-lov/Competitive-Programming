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

int N,K;
int sl[1005][1005];
int tc=0;
int main() {
	ifstream cin("paintbarn.in");
	ofstream cout("paintbarn.out");
	cin>>N>>K;
	int a,b,x,y;
	for(int i=0;i<N;i++){
		cin>>a>>b>>x>>y;
		for(int j=a;j<x;j++){
			sl[j][b]+=1;
			sl[j][y]-=1;
		}
	}
	for(int i=0;i<1001;i++){
		int cc=0;
		for(int j=0;j<1001;j++){
			cc+=sl[i][j];
			if(cc==K){
				tc++;
			}
		}
	}
	cout<<tc<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/