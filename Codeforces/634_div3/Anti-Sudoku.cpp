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

char board[9][9];
int cx[]={0,3,6,1,4,7,2,5,8};
int cy[]={0,1,2,3,4,5,6,7,8};

void tnv(){
	for(int i=0;i<9;i++){
		if(board[cx[i]][cy[i]]=='9'){
			board[cx[i]][cy[i]]='1';
		}else{
			board[cx[i]][cy[i]]++;
		}
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>board[i][j];
			}
		}
		tnv();
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j];
			}
			cout<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/