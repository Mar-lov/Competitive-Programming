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
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int T;
int R;
vector<string> seq;
unordered_map<string,short> codon;
set< deque<short> > vals;
deque<short> cur[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ifstream cin("rna.in");

	cin>>T;
	string cis;
	for(int i=0;i<T;i++){
		cin>>cis;
		seq.push_back(cis);
	}
	int civ;
	for(int i=0;i<64;i++){
		cin>>cis>>civ;
		codon[cis]=civ;
		//cout<<cis<<" "<<civ<<'\n';
	}
	cin>>R;
	R/=3;
	for(int i=0;i<T;i++){
		vals.clear();
		cur[0].clear();
		cur[1].clear();
		cur[2].clear();
		int ci=0;
		string s=seq[i];
		string cs="";
		for(int i=s.size()-1;i>=0;i--){
			if(cs.size()<2){
				cs=s[i]+cs;
				continue;
			}
			cs=s[i];
			cs+=s[i+1];
			cs+=s[i+2];
			//cout<<cs<<" "<<codon[cs]<<'\n';
			cur[ci].push_front(codon[cs]);
			if(cur[ci].size()==R){
				vals.insert(cur[ci]);
				cur[ci].pop_back();
			}
			ci=(ci+1)%3;
		}
		cout<<vals.size()<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/