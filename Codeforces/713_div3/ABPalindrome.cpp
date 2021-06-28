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

int T;
int val[2];
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ofstream cout("val.out");
	cin>>T;
	while(T--){
		cin>>val[0]>>val[1];
		int N=val[0]+val[1];
		cin>>s;
		string h1="",h2="";
		for(int i=0;i<((N)/2);i++){
			h1+=s[i];
			h2+=s[N-1-i];
		}
		bool works=true;
		for(int i=0;i<N/2;i++){
			if(h1[i]!='?'&&h2[i]!='?'&&h1[i]==h2[i]){
				val[(int)(h1[i]-'0')]-=2;
			}else if(h1[i]!='?'&&h2[i]=='?'){
				val[(int)(h1[i]-'0')]-=2;
				h2[i]=h1[i];
			}else if(h1[i]=='?'&&h2[i]!='?'){
				val[(int)(h2[i]-'0')]-=2;
				h1[i]=h2[i];
			}else if(h1[i]!='?'&&h2[i]!='?'&&h1[i]!=h2[i]){
				works=false;
			}
		}
		if(val[0]<0||val[1]<0) works=false;
		for(int i=0;i<N/2;i++){
			if(h1[i]=='?'&&h2[i]=='?'){
				if(val[0]>1){
					val[0]-=2;
					h1[i]='0';
					h2[i]='0';
				}else if(val[1]>1){
					val[1]-=2;
					h1[i]='1';
					h2[i]='1';
				}else{
					works=false;
				}
			}
		}
		string mid="";
		if(N%2==1){
			if(s[(N/2)]!='?'){
				if(val[s[(N/2)]-'0']>0){
					mid=s[(N/2)];
					val[s[(N/2)]-'0']--;
				}else{
					works=false;
				}
			}else{
				if(val[0]>0){
					mid="0";
				}else{
					mid="1";
				}
			}
		}
		if(works){
			reverse(h2.begin(),h2.end());
			if(N%2==1){
				cout<<h1<<mid<<h2<<endl;
			}else{
				cout<<h1<<h2<<endl;
			}
		}else{
			cout<<"-1"<<endl;
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