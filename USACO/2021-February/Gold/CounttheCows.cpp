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

int N;

bool isSpecial(int x,int y){
	for(int k=0;k<39;k++){
		if((((int)floor(x/pow(3,k)))%3)%2!=(((int)floor(y/pow(3,k)))%3)%2) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			/*
			if(isSpecial(i,j)) cout<<'8';
			else cout<<'-';
			*/
			if(isSpecial(i,j)&&i+40==j) cout<<i<<","<<j<<endl;
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