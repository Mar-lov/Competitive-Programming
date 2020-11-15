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

#define maxN 1005

struct loc{
	int x,y,s;
};

int N;
loc city[maxN];
int p[maxN];

int findP(int n){
	if(n==p[n]) return n;
	return findP(p[n]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>city[i].x>>city[i].y>>city[i].s;
		p[i]=i;
	}

	for(int i=0;i<N;i++){
		int cn=0;
		int cd=1;
		int tt=0;
		int lc=-1;
		for(int j=0;j<N;j++){
			if(i==j) continue;
			int dist=pow(city[i].x-city[j].x,2)+pow(city[i].y-city[j].y,2);
			if(city[i].s*dist<city[j].s){
				if(cn*dist<city[j].s*cd){
					cn=city[j].s;
					cd=dist;
					tt=1;
					lc=j;
				}else if(cn*dist==city[j].s*cd){
					tt++;
				}
			}
		}
		//cout<<lc<<" "<<cm<<" "<<lc<<'\n';
		if(tt==1){
			p[i]=lc;
		}else if(tt>1){
			p[i]=-1;
		}
	}

	for(int i=0;i<N;i++){
		if(p[i]==-1){
			cout<<"D"<<'\n';
		}else if(p[i]==i){
			cout<<"K"<<'\n';
		}else{
			cout<<findP(i)+1<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/