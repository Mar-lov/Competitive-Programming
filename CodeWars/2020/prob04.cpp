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

int gcd(int a,int b){
	int R;
	while(a%b>0){
		R=a%b;
		a=b;
		b=R;
	}
	return b;
}


int main() {
	int X,Y;
	cin>>X>>Y;
	cout<<(X*Y)/gcd(X,Y);
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/