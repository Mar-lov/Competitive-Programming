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

#define maxN 405

int T;
int N;
char grid[maxN][maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		vector< pair<int,int> > vals;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>grid[i][j];
				if(grid[i][j]=='*'){
					vals.push_back(make_pair(i,j));
				}
			}
		}
		if(vals[0].first==vals[1].first){
			if(vals[0].first==0){
				vals[0].first=1;
				vals[1].first=1;
			}else{
				vals[0].first=0;
				vals[1].first=0;
			}
		}
		if(vals[0].second==vals[1].second){
			if(vals[0].second==0){
				vals[0].second=1;
				vals[1].second=1;
			}else{
				vals[0].second=0;
				vals[1].second=0;
			}
		}
		grid[vals[0].first][vals[1].second]='*';
		grid[vals[1].first][vals[0].second]='*';
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<grid[i][j];
			}
			cout<<endl;
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