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

#define maxN 500

int N,M;
string spot[maxN];
string plain[maxN];

bool found(int len){
	for(int i=0;i+len<M;i++){
		unordered_set<string> shas,phas,bhave;
		for(int j=0;j<N;j++){
			//cout<<spot[j].substr(i,len)<<" "<<plain[j].substr(i,len)<<'\n';
		shas.insert(spot[j].substr(i,len));
		phas.insert(plain[j].substr(i,len));
		bhave.insert(spot[j].substr(i,len));
		bhave.insert(plain[j].substr(i,len));
	}
	if(bhave.size()==shas.size()+phas.size()) return true;
	}
	return false;
}

int main() {
	ifstream cin("cownomics.in");
	ofstream cout("cownomics.out");
	cin>>N>>M;
	cin.ignore();
	for(int i=0;i<N;i++){
		getline(cin,spot[i]);
		//cout<<spot[i]<<"\n";
	}
	for(int i=0;i<N;i++){
		getline(cin,plain[i]);
		//cout<<plain[i]<<"\n";
	}
	int lo=0;
	int hi=M;
	while(lo<hi){
		int mid=(lo+hi)/2;
		//cout<<lo<<" "<<hi<<'\n';
		if(found(mid)){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	cout<<lo<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/