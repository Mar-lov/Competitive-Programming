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

int t;
int a,b;
int lc=0;
int row[8];

bool place(int r,int c){
	for(int i=0;i<c;i++){
		if(row[i]==r||abs(row[i]-r)==abs(i-c)) return false;
	}
	return true;
}

void backtrack(int c){
	if(c==8&&row[b]==a){
		lc++;
		cout<<(lc>9?"":" ")<<lc<<"     ";
		for(int i=0;i<8;i++){
			cout<<" "<<row[i]+1;
		}
		cout<<'\n';
	}else{
		for(int i=0;i<8;i++){
			if(place(i,c)){
				row[c]=i;
				backtrack(1+c);

			}
		}
	}
}

int main() {
	cin>>t;
	while(t--){
		cin>>a>>b;a--;b--;
		lc=0;
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		fill(row,row+8,0);
		backtrack(0);
		cout<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/