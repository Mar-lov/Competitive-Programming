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

int solve(int x,int y){
	if(x>0&&y>0)return 1;
	else if(x<0&&y>0) return 2;
	else if(x<0&&y<0) return 3;
	else if(x>0&&y<0) return 4;
	return 0;
}


int main() {
	int x,y;
	cin>>x>>y;
	cout<<solve(x,y)<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/