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

bool isVowel(char a){
	return a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
}
bool isConstant(char a){
	return !isVowel(a);
}
bool isCopy(vector<string> arr){
	for(int i=0;i<arr.size()-1;i++){
		if(arr[i]!=arr[i+1]) return false;
	}
	return true;
}
bool isShm(vector<string> arr){
	if(arr.size()!=2) return false;
	if(arr[1].substr(0,3)=="SHM"&&arr[0].substr(0,3)!="SHM") return true;
	return false;
}
bool isAblaut(vector<string> arr){
	for(int i=0;i<arr.size()-1;i++){
		if(arr[i].length()!=arr[i+1].length()) return false;
	}
	int AEL=0;
	for(int i=0;i<arr[0].length();i++){
		bool ae=true;
		for(int j=0;j<arr.size()-1;j++){
			if(arr[j][i]!=arr[j+1][i]) ae=false;
		}
		if(ae) AEL++;
		if(!ae){
			for(int j=0;j<arr.size();j++){
				if(!isVowel(arr[j][i])) return false;
			}
		}
	}
	return AEL==(arr[0].length()-1);
}
map<char,int> VV;


bool isProg(vector<string> arr){
	int ci=0;
	for(int i=0;i<arr[0].length();i++){
		bool ae=true;
		for(int j=0;j<arr.size()-1;j++){
			if(arr[j][i]!=arr[j+1][i]) ae=false;
		}
		if(!ae) ci=i; 
	}
	vector<char> order;
	for(int i=0;i<arr.size();i++){
		order.push_back(arr[i][ci]);
	}
	for(int i=0;i<order.size()-1;i++){
		if(VV[order[i]]>=VV[order[i+1]]) return false;
	}
	return true;
}

int main() {
	VV['I']=0;
	VV['A']=1;
	VV['E']=2;
	VV['O']=3;
	VV['U']=4;
	int N;
	cin>>N;
	while(N>0){
		vector<string> arr;
		string cur;
		for(int i=0;i<N;i++){
			cin>>cur;
			arr.push_back(cur);
		}
		//output line
		for(int i=0;i<N;i++){
			cout<<arr[i]<<" ";
		}
		if(isCopy(arr)){
			cout<<"COPY"<<'\n';
		}else if(isShm(arr)){
			cout<<"SHM"<<'\n';
		}else if(isAblaut(arr)){
			if(isProg(arr)){
				cout<<"PROGRESSIVE"<<'\n';
			}else{
				cout<<"ABLAUT"<<'\n';
			}		
		}else{
			cout<<"RHYMING"<<'\n';
		}
	
		cin>>N;
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/