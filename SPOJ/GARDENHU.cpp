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
typedef double ll;
typedef pair<double,double> ii;

#define maxN 10005

struct Point{
	double x,y;
	/*Point(double a,double b){
		x=a;
		y=b;
	}*/
};

bool cmp(Point a,Point b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int N;
Point arr[maxN];

bool ccw(Point a,Point b,Point c){
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))>=0;
}

bool cw(Point a,Point b,Point c){
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))<=0;
}

vector<Point> solveTopHull(){
	int ci=0;
	vector<Point> cur;
	cur.push_back(arr[ci]);
	ci++;
	while(ci<N){
		cur.push_back(arr[ci]);

		if(cur.size()<3){
			ci++;
			continue;
		}

		while(cur.size()>2&&ccw(cur[cur.size()-3],cur[cur.size()-2],cur[cur.size()-1])){
			cur.pop_back();
			cur.pop_back();
			cur.push_back(arr[ci]);
		}
		ci++;
	}
	return cur;
}

vector<Point> solveBottomHull(){
	int ci=0;
	vector<Point> cur;
	cur.push_back(arr[ci]);
	ci++;
	while(ci<N){
		cur.push_back(arr[ci]);
		
		if(cur.size()<3){
			ci++;
			continue;
		}

		while(cur.size()>2&&cw(cur[cur.size()-3],cur[cur.size()-2],cur[cur.size()-1])){
			cur.pop_back();
			cur.pop_back();
			cur.push_back(arr[ci]);
		}
		ci++;
	}
	return cur;
}

double dist(Point a,Point b){
	return sqrt(pow((double)a.x-(double)b.x,2.0)+pow((double)a.y-(double)b.y,2.0));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	double ix,iy;
	for(int i=0;i<N;i++){
		cin>>ix>>iy;
		arr[i].x=ix;
		arr[i].y=iy;
	}
	sort(arr,arr+N,cmp);
	
	vector<Point> topHull=solveTopHull();

	vector<Point> bottomHull=solveBottomHull();
	topHull.pop_back();
	reverse(bottomHull.begin(),bottomHull.end());
	//bottomHull.pop_back();
	for(double i=0;i<bottomHull.size();i++){
		topHull.push_back(bottomHull[i]);
	}

	double result=0;
	for(double i=1;i<topHull.size();i++){
		//cout<<topHull[i].x<<" "<<topHull[i].y<<'\n';
		result+=(dist(topHull[i],topHull[i-1]));
	}
	cout<<round(result)<<'\n';
    return 0;
}

/* stuff you should look for
	* double overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/