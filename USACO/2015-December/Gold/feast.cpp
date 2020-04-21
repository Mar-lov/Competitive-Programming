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

int T,A,B;
bool knap[5000005];
int lastp[5000005];

int main() {
	ifstream cin("feast.in");
	ofstream cout("feast.out");
	cin>>T>>A>>B;
	knap[0]=true;
	for(int i=0;i<=T;i++){
		if(knap[i]){
			if(i+A<=T) knap[i+A]=true;
			if(i+B<=T) knap[i+B]=true;
		}
	}	
	int lp=0;
	for(int i=0;i<=T;i++){
		if(knap[i]) lp=i;
		lastp[i]=lp;
	}
	int maxV=0;
	for(int i=0;i<=T;i++){
		if(knap[i]){
		maxV=max(maxV,min((i/2)+lastp[T-(i/2)],T));
		}
	}
	cout<<max(maxV,lastp[T])<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/