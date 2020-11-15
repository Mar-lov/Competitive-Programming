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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int T;
char grid[3][3];

int val(char c){
	if(c=='X') return 1;
	if(c=='O') return 2;
	return 0;
}

int r1(){
	if(grid[0][0]==grid[0][1]&&grid[0][1]==grid[0][2]){
		return val(grid[0][0]);
	}
	return 0;
}
int r2(){
	if(grid[1][0]==grid[1][1]&&grid[1][1]==grid[1][2]){
		return val(grid[1][0]);
	}
	return 0;
}
int r3(){
	if(grid[2][0]==grid[2][1]&&grid[2][1]==grid[2][2]){
		return val(grid[2][0]);
	}
	return 0;
}
int c1(){
	if(grid[0][0]==grid[1][0]&&grid[1][0]==grid[2][0]){
		return val(grid[0][0]);
	}
	return 0;
}
int c2(){
	if(grid[0][1]==grid[1][1]&&grid[1][1]==grid[2][1]){
		return val(grid[0][1]);
	}
	return 0;
}
int c3(){
	if(grid[0][2]==grid[1][2]&&grid[1][2]==grid[2][2]){
		return val(grid[0][2]);
	}
	return 0;
}
int d1(){
	if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]){
		return val(grid[1][1]);
	}
	return 0;
}
int d2(){
	if(grid[2][0]==grid[1][1]&&grid[1][1]==grid[0][2]){
		return val(grid[1][1]);
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while(T--){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>grid[i][j];
			}
		}
		int nX=0,nO=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(grid[i][j]=='X') nX++;
				if(grid[i][j]=='O') nO++;
			}
		}
		multiset<int> wins;
		wins.insert(r1());
		wins.insert(r2());
		wins.insert(r3());
		wins.insert(c1());
		wins.insert(c2());
		wins.insert(c3());
		wins.insert(d1());
		wins.insert(d2());
		int Xw=wins.count(1);
		int Ww=wins.count(2);
		//cout<<nX<<" "<<nO<<" and "<<Xw<<" "<<Ww<<'\n';
		if(nX<nO){
			cout<<"no"<<'\n';
		}else if(nX-1>nO){
			cout<<"no"<<'\n';
		}else if(Xw>0&&Ww>0){
			cout<<"no"<<'\n';
		}else if(Xw==0&&Ww==1&&nX!=nO){
			cout<<"no"<<'\n';
		}else if(Xw==1&&Ww==0&&nX-1!=nO){
			cout<<"no"<<'\n';
		}else{
			cout<<"yes"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/