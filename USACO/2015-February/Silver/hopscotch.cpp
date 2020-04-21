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

int R,C,K;
int grid[105][105];
ll cgt[105][105];
bool visited[105][105];
int hmgf(int x,int y){
	for(int i=x+1;i<R;i++){
		for(int j=y+1;j<C;j++){
			if(grid[i][j]!=grid[x][y]){
				if(visited[i][j]) cgt[x][y]+=cgt[i][j];
				else cgt[x][y]+=hmgf(i,j);			
			}
		}
	}
	visited[x][y]=true;
	cgt[x][y]%=1000000007;
	return cgt[x][y];
}
int main() {
	ifstream cin("hopscotch.in");
	ofstream cout("hopscotch.out");
	cin>>R>>C>>K;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>grid[i][j];
		}
	}
	cgt[R-1][C-1]=1;
	visited[R-1][C-1]=true;	
	for(int i=0;i<C;i++){
		visited[R-1][i]=true;
	}
	for(int i=0;i<R;i++){
		visited[i][C-1]=true;
	}
	cout<<hmgf(0,0)%1000000007<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/