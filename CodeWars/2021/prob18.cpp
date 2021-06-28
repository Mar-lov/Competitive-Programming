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

string name;
double peopleNeeded;
double totalTime;
double startUp;
double powerOutput;
double peopleFound;

double gene=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin,name);
	cin>>peopleNeeded>>totalTime>>startUp>>powerOutput>>peopleFound;
	totalTime*=60.0;
	powerOutput/=3600.0;
	double timeG=60*60.0;
	gene=0;
	if(peopleNeeded<=peopleFound){
		timeG-=startUp;
		if(timeG>0){
			gene+=powerOutput*(min(timeG,totalTime));
		}else{
			gene=0;
		}
	}else{
		gene=0;
	}
	cout<<fixed;

	cout<<setprecision(2)<<name<<" can generate "<<(gene>0?powerOutput:0)<<" watts/second"<<endl;
	if(gene>=1210000000){
		cout<<"MARTY CAN MAKE IT!"<<endl;
	}else{
		cout<<"WHOA, HEAVY!"<<endl;
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