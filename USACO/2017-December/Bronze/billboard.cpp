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
typedef pair<int,int> pi;

struct rect{
	int x1,x2,y1,y2;
};

rect arr[3];

int area(rect a){
	return (a.x2-a.x1)*(a.y2-a.y1);
}

int share(rect a,rect b){
	if(min(a.x2,b.x2)-max(a.x1,b.x1)<0||min(a.y2,b.y2)-max(a.y1,b.y1)<0) return 0;
	return (min(a.x2,b.x2)-max(a.x1,b.x1))*(min(a.y2,b.y2)-max(a.y1,b.y1));
}

int main() {
	ifstream cin("billboard.in");
	ofstream cout("billboard.out");

	for(int i=0;i<3;i++){
		cin>>arr[i].x1>>arr[i].y1>>arr[i].x2>>arr[i].y2;
	}


	cout<<area(arr[0])+area(arr[1])-share(arr[0],arr[2])-share(arr[1],arr[2])<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/