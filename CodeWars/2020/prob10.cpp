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


string sent;
int cai[4];
vector<string> arr[4];

void solve(){
	for(int i=0;i<sent.length();i++){
		if(sent[i]=='['){
			string inside;
			int ci=i+1;
			while(sent[ci]!=']'&&inside.length()<3){
				inside+=sent[ci];
				ci++;
			}
			if(inside=="N"){
				cout<<arr[0][cai[0]];
				cai[0]++;
				i+=2;
			}else if(inside=="AV"){
				cout<<arr[1][cai[1]];
				cai[1]++;
				i+=3;
			}else if(inside=="V"){
				cout<<arr[2][cai[2]];
				cai[2]++;
				i+=2;
			}else if(inside=="AJ"){
				cout<<arr[3][cai[3]];
				cai[3]++;
				i+=3;
			}else{
				cout<<sent[ci];
			}
		}else{
			cout<<sent[i];
		}
	}
}

int main() {
	getline(cin,sent);
	string cur;
	getline(cin,cur);
	getline(cin,cur);
	while(cur!="ADVERBS"){
		arr[0].push_back(cur);
		getline(cin,cur);
	}
	getline(cin,cur);
	while(cur!="VERBS"){
		arr[1].push_back(cur);
		getline(cin,cur);
	}
	getline(cin,cur);
	while(cur!="ADJECTIVES"){
		arr[2].push_back(cur);
		getline(cin,cur);
	}
	getline(cin,cur);
	while(cur!="END"){
		arr[3].push_back(cur);
		getline(cin,cur);
	}
	solve();
	cout<<'\n';
	solve();	
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/