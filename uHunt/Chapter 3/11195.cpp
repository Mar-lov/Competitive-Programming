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

int n;
char board[20][20];
int solutions=0;
int cs=0;
bitset<30> ld,rd,rw;

void solve(int c){
	if(c==n){
		solutions++;
	}else{
		for(int i=0;i<n;i++){
			if(board[i][c]!='*'&&!rw[i]&&!)
		}
	}
}
int main() {
	cin>>n;
	while(n!=0){
		solutions=0;
		ld.reset();rd.reset();rw.reset();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>board[i][j];
			}
		}
		solve(0);
		cout<<"Case "<<++cs<<": "<<solutions<<'\n';
		cin>>n;
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/