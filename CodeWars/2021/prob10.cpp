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

vector<string> bad;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	getline(cin,s);

	while(s!="END"){
		stringstream ss(s);
		string p1,p2,p3;
		ss>>p1;
		ss>>p2;
		ss>>p3;
		string name="";
		name+=p1[9];
		name+=p1[10];	
		string hrs="";
		hrs+=p2[0];
		hrs+=p2[1];
		string mins="";
		mins+=p2[3];
		mins+=p2[4];
		int ctime=60*stoi(hrs)+stoi(mins);
		int VPF=stoi(p3);
		VPF*=10;
		//cout<<name<<" "<<VPF+ctime<<'\n';
		if(VPF+ctime<1020){
			bad.push_back(name);
		}
		getline(cin,s);
	}

	if(bad.size()==0){
		cout<<"Blah, blah, blah, time to order delivery"<<endl;
	}else{
		cout<<"Villager ";
		cout<<"(";
		for(int i=0;i<bad.size();i++){
			cout<<bad[i]<<(i+1!=bad.size()?", ":")");
		}
		cout<<" look tasty"<<endl;
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