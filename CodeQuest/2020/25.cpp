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
double R(double n){ return round(n); }



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	for(int z=0;z<T;z++){
		int t;
		string ci;
		cin>>t>>ci;
		bool seen[26];
		fill(seen,seen+26,false);
		map<char, int > toLoc;
		map<char,int> bt;
		int valn=0;
		for(int i=0;i<ci.length();i++){
			if(ci[i]=='J') continue;
			if(!seen[ci[i]-'A']){
				toLoc[ci[i]]=valn;
				bt[valn]=tolower(ci[i]);
				valn++;
				seen[ci[i]-'A']=true;
			}
		}
		for(int i=0;i<26;i++){
			if(i==('J'-'A')) continue;
			if(!seen[i]){
				toLoc[(char)(i+'A')]=valn;
				bt[valn]=tolower((char)(i+'A'));
				valn++;
				seen[i]=true;
			}
		}
		string de;
		for(int c=0;c<t;c++){
			cin>>de;
			string ans="";
			for(int i=0;i<de.length();i+=2){
				int fl=toLoc[de[i]];
				int sl=toLoc[de[i+1]];
				int fr=fl/5;
				int fc=fl%5;
				int sr=sl/5;
				int sc=sl%5;
				int nf=fl;
				int ns=sl;
				if(fr==sr){
					nf=(nf-1)+((nf-1)/5!=fr?5:0);
					ns=(ns-1)+((ns-1)/5!=sr?5:0);
				}else if(fc==sc){
					nf=fc+5*(fr-1+(fr-1==-1?5:0));
					ns=sc+5*(sr-1+(sr-1==-1?5:0));
				}else{
					nf=5*fr+sc;
					ns=5*sr+fc;
				}
				ans+=bt[nf];
				ans+=bt[ns];
			}
			cout<<ans<<endl;
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