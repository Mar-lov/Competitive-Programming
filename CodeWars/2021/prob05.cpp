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
vector<string> arr;
int dups;
multiset<string> has;
vector<string> d;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	string input;
	for(int i=0;i<N;i++){
		cin>>input;
		string ns="";
		for(int i=0;i<5;i++){
			ns+=input[i];
		}
		arr.push_back(ns);
	}
	for(int i=0;i<N;i++){
		if(has.count(arr[i])==1){
			dups++;
			d.push_back(arr[i]);
		}
		has.insert(arr[i]);
	}
	if(dups==0){
		cout<<"0"<<endl<<"duplicates: None"<<endl;
	}else{
		cout<<dups<<endl;
		cout<<"duplicates: ";
		for(int i=0;i<dups;i++){
			cout<<d[i]<<" ";
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