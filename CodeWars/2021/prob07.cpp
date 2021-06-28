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

#define PI 3.14159265

map<string,int> skiMaterial;
map<string,int> surface;

double vals[3][5]={{.90,.80,.70,1.15,.15},{.62,.42,.30,.80,.05},{.57,.30,.74,.70,.03}};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	skiMaterial["RUBBER"]=0;
	skiMaterial["WOOD"]=1;
	skiMaterial["STEEL"]=2;
	surface["CONCRETE"]=0;
	surface["WOOD"]=1;
	surface["STEEL"]=2;
	surface["RUBBER"]=3;
	surface["ICE"]=4;
	string sM,sF;
	cin>>sM>>sF;
	int f=skiMaterial[sM];
	int s=surface[sF];
	cout<<fixed;
	cout<<setprecision(2)<<vals[f][s];
	cout<<setprecision(1)<<" "<<atan(vals[f][s])*(180.0/PI)<<endl;
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/