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

struct pony{
	string name;
	int type;
};

vector<pony> names;

map<string,int> gem;
int findT(string s){
	stringstream ss(s);
	string quick;
	int lr=12;
	while(ss>>quick){
		if(gem.count(quick)){
			lr=min(lr,gem[quick]);
		}
	}
	return lr;
}

bool cmp(pony a,pony b){
	if(a.type==b.type){
		return a.name<b.name;
	}
	return a.type<b.type;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	gem["Lapis"]=0;
	gem["Topaz"]=1;
	gem["Tourmaline"]=2;
	gem["Sapphire"]=3;
	gem["Peridot"]=4;
	gem["Ruby"]=5;
	gem["Pearl"]=6;
	gem["Emerald"]=7;
	gem["Diamond"]=8;
	gem["Aquamarine"]=9;
	gem["Amethyst"]=10;
	gem["Garnet"]=11;

	string cur;
	getline(cin,cur);
	while(cur!="END"){
		pony now;
		now.name=cur;
		now.type=findT(cur);
		names.push_back(now);
		getline(cin,cur);
	}
	sort(names.begin(),names.end(),cmp);
	for(int i=0;i<names.size();i++){
		cout<<names[i].name<<endl;
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