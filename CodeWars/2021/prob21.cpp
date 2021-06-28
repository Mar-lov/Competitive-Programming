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

#define maxN 30

vector<string> arr;

char name[4]={'M','O','J','O'};

bool horzL(int i,int j){
	if(j<=2) return false;
	bool works=true;
	for(int d=0;d<4;d++){
		if(arr[i][j-d]!=name[d]) works=false;
	}
	if(works==false) return works;
	for(int d=0;d<4;d++){
		cout<<name[d]<<": "<<j-d<<","<<i<<endl;
	}
	return true;
}
bool horzR(int i,int j){
	if(j>=arr[i].size()-3) return false;
	bool works=true;
	for(int d=0;d<4;d++){
		if(arr[i][j+d]!=name[d]) works=false;
	}
	if(works==false) return works;
	for(int d=0;d<4;d++){
		cout<<name[d]<<": "<<j+d<<","<<i<<endl;
	}
	return true;
}
bool vertU(int i,int j){
	if(i<=2) return false;
	bool works=true;
	for(int d=0;d<4;d++){
		if(arr[i-d][j]!=name[d]) works=false;
	}
	if(works==false) return works;
	for(int d=0;d<4;d++){
		cout<<name[d]<<": "<<j<<","<<i-d<<endl;
	}
	return true;
}
bool vertD(int i,int j){
	if(i>=arr.size()-3) return false;
	bool works=true;
	for(int d=0;d<4;d++){
		if(arr[i+d][j]!=name[d]) works=false;
	}
	if(works==false) return works;
	for(int d=0;d<4;d++){
		cout<<name[d]<<": "<<j<<","<<i+d<<endl;
	}
	return true;
}
bool square(int i,int j){
	if(i>=arr.size()-1||j>=arr[i].size()-1) return false;
	if(arr[i][j]==name[0]&&arr[i][j+1]==name[1]&&arr[i+1][j]==name[2]&&arr[i+1][j+1]==name[3]){
		cout<<name[0]<<" "<<j<<","<<i<<endl;
		cout<<name[1]<<" "<<j+1<<","<<i<<endl;
		cout<<name[2]<<" "<<j<<","<<i+1<<endl;
		cout<<name[3]<<" "<<j+1<<","<<i+1<<endl;
		return true;
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	/*
	for(int i=0;i<25;i++){
		cout<<i<<endl;
		cin>>s;
		if(s.length()>0&&s[0]>='A'&&s[0]<='Z'){
			arr.push_back(s);
		}
	}*/
	while(cin>>s){
		arr.push_back(s);
	}
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<(int)arr[i].length();j++){
			//cout<<i<<" "<<j<<endl;
			if(horzL(i,j)) return 0;
			if(horzR(i,j)) return 0;
			if(vertU(i,j)) return 0;
			if(vertD(i,j)) return 0;
			if(square(i,j)) return 0;
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