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

int a,b,c,d;
int x;
int y;
int x1;
int y3;
int x2;
int y2;

bool inbounds(int cx,int cy){
	if(cx>=x1&&cx<=x2&&cy>=y3&&cy<=y2) return true;
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		cin>>x>>y>>x1>>y3>>x2>>y2;
		int hor=b-a;
		int vert=d-c;
		if(inbounds(x+hor,y+vert)&&hor>=x1-x&&hor<=x2-x&&vert>=y3-y&&vert<=y2-y&&(x2-x1>=1||y2-y3>=1)){
			cout<<"Yes"<<'\n';
		}else{
			cout<<"No"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/