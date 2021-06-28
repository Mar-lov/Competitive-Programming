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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
double R(double n){ return round(n); }

#define INF 1000000000

int dist(int a,int b,int x,int y){
	return abs(a-x)+abs(b-y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int z=0;z<T;z++){
		int x1,y1,r1,x2,y2,r2,x3,y3,r3;
		cin>>x1>>y1>>r1>>x2>>y2>>r2>>x3>>y3>>r3;
        int mnx=INF;
	int mxx=-INF;
	int mny=INF;
	int mxy=-INF;
		mnx=min(x1-r1,min(x2-r2,x3-r3));
		mxx=max(x1+r1,max(x2+r2,x3+r3));
		mny=min(y1-r1,min(y2-r2,y3-r3));
		mxy=max(y1+r1,max(y2+r2,y3+r3));
		for(int x=mnx;x<=mxx;x++){
		for(int y=mny;y<=mxy;y++){
			if(dist(x,y,x1,y1)==r1&&dist(x,y,x2,y2)==r2&&dist(x,y,x3,y3)==r3){
				cout<<"("<<x<<","<<y<<")"<<endl;
				break;
			}
		}
	}
	}
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/