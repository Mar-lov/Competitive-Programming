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

double num;
string SIZER;
double SI;
double power;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>num>>SIZER>>power;
	if(SIZER=="3"){
		SI=3.0;
	}else if(SIZER=="2"){
		SI=2.0;
	}else if(SIZER=="1"){
		SI=1.0;
	}else if(SIZER=="1/2"){
		SI=.5;
	}else if(SIZER=="1/3"){
		SI=.3333333;
	}else if(SIZER=="1/4"){
		SI=.25;
	}
	double total=num*SI*.45*7.5;
	cout<<fixed;
	if(total<=power){
		cout<<setprecision(2)<<total<<" the Mask can eat it!";
	}else{
		cout<<setprecision(2)<<total<<" the Mask should not eat it! ";
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