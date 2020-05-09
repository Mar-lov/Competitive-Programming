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


string solve(string a,string b){
	if(a==b) return a;
	if(a>b)swap(a,b);
	if(a=="BLACK"){
		return "DARK "+b;
	}else if(a=="WHITE"&&b=="YELLOW"){
		return "LIGHT YELLOW";
	}else if(b=="WHITE"){
		return "LIGHT "+a;
	}else if(a=="BLUE"&&b=="RED"){
		return "PURPLE";
	}else if(a=="BLUE"&&b=="YELLOW"){
		return "GREEN";
	}else if(a=="RED"&&b=="YELLOW"){
		return "ORANGE";
	}
	return "";
}


int main() {
	string a,b;
	while(cin>>a>>b){
		cout<<solve(a,b)<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/