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

#define maxN 5005
#define maxQ 100005

int N,Q;
int arr[maxN];
pair<int,int> query[maxQ];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>Q;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<Q;i++){
		cin>>query[i].first>>query[i].second;
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