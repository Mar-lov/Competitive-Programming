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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

char toH[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
string toHex(int x){
	string ans="";
	while(x>0){
		ans=toH[x%16]+ans;
		x/=16;
	}
	return ans;
}

int fromHex(string x){
	int ans=0;
	for(int i=0;i<x.length();i++){
		char cc=x[x.length()-1-i];
		if(cc>='a'&&cc<='f'){
			ans+=pow(16,i)*((int)(cc-'a')+10);
		}else{
			ans+=pow(16,i)*(int(cc-'0'));
		}
	}
	return ans;
}

string puzzle,prompt;
vector<string> inHex;
string pa="";
int main() {
	getline(cin,puzzle);
	getline(cin,prompt);
	for(int i=0;i<puzzle.length();i++){
		if((puzzle[i]>='a'&&puzzle[i]<='z')||(puzzle[i]>='A'&&puzzle[i]<='Z')){
			inHex.push_back(toHex(puzzle[i]));
		}
	}
	for(int i=inHex.size()-1;i>=0;i-=2){
		pa=inHex[i][inHex[i].length()-1]+pa;
	}
	for(int i=0;i<inHex.size();i++){
		cout<<inHex[i]<<" ";
	}
	cout<<'\n';
	cout<<pa<<'\n';
	for(int i=0;i<pa.size();i+=2){
		string ns="";
		ns+=pa[i];
		ns+=pa[i+1];
		//cout<<ns<<'\n';
		cout<<(char)fromHex(ns);
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/