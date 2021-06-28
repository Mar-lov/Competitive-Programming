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

#define maxN 200005

int N;
int T;
vector< pair<int,int> > pts;
vector<int> cv;
int dp[maxN];
int 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>T;
	int ix,iy;
	for(int i=0;i<N;i++){
		cin>>ix>>iy;
		pts.push_back(make_pair(ix,iy));
	}
	pts.push_back(make_pair(0,0));

	sort(pts.begin(),pts.end());



    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/