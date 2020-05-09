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

bool isPrime(int X){
	for(int i=2;i<=sqrt(X);i++){
		if(X%i==0) return false;
	}
	return true;
}


int main() {
	int X;
	cin>>X;
	if(isPrime(X)&&X>1){
		cout<<X<<" is PRIME";
	}else{
		cout<<X<<" is NOT Prime";
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/