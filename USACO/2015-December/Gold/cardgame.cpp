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

#define maxN 100001

int N;
vector<int> efh,esh,bfh,bsh;
bool ev[maxN];
int ans=0;
int main() {
	ifstream cin("cardgame.in");
	ofstream cout("cardgame.out");
	cin>>N;
	int curval;
	for(int i=0;i<N/2;i++){
		cin>>curval;
		ev[curval]=true;
		efh.push_back(curval);
	}
	for(int i=0;i<N/2;i++){
		cin>>curval;
		ev[curval]=true;
		esh.push_back(curval);
	}
	sort(efh.begin(),efh.end());
	sort(esh.begin(),esh.end());

	for(int i=2*N;i>0;i--){
		if(ev[i]==false){
		if(bfh.size()<N/2){
			bfh.push_back(i);
		}else{
			bsh.push_back(i);
		}
		}
	}
	reverse(bfh.begin(),bfh.end());
	reverse(esh.begin(),esh.end());
	int ci=0;

	for(int i=0;i<N/2;i++){
		while(ci<bfh.size()&&bfh[ci]<efh[i]){
			ci++;
		}
		 if(ci<bfh.size()&&bfh[ci]>efh[i]){
			 //cout<<ci<<i<<'\n';
			 ci++;
			 ans++;
		 }
		 if(ci==bfh.size()){
			 break;
		 }
	}
	ci=0;
	for(int i=0;i<N/2;i++){
		while(ci<bsh.size()&&bsh[ci]>esh[i]){
			ci++;
		}
		if(ci<bsh.size()&&bsh[ci]<esh[i]){
			//cout<<ci<<i<<'\n';
			ci++;
			ans++;
		}
		if(ci==bsh.size()){
			break;
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