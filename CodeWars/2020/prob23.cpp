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


int N;
map< char , char > con;

string clean(string s){
	string ans;
	for(int i=0;i<s.length();i++){
		if(s[i]>='a'&&s[i]<='z'){
			ans+=s[i];
		}else if(s[i]>='A'&&s[i]<='Z'){
			ans+=(char)((s[i]-'A')+'a');
		}else if(s[i]==' '){
			ans+=' ';
		}
	}
	return ans;
}

string rot180(string s){
	string r="";
	for(int i=0;i<s.length();i++){
		r+=con[s[i]];
	}
	return r;
}

bool areEqual(string a,string b){
	int p1=0;
	int p2=0;
	while(p1<a.length()&&p2<b.length()){
		if(a[p1]==' '){
			p1++;
			continue;
		}
		if(b[p2]==' '){
			p2++;
			continue;
		}
		if(a[p1]!=b[p2]) return false;
		if(con.find(a[p1])==con.end()) return false;
		p1++;p2++;
	}
	return true;
}

int main() {
	con['o']='o';
	con['s']='s';
	con['x']='x';
	con['z']='z';
	con['a']='e';
	con['e']='a';
	con['b']='q';
	con['q']='b';
	con['d']='p';
	con['p']='d';
	con['h']='y';
	con['y']='h';
	con['m']='w';
	con['w']='m';
	con['n']='u';
	con['u']='n';
	con[' ']=' ';
	cin>>N;
	cin.ignore();
	string s;
	string r;
	while(N--){
		getline(cin,s);
		s=clean(s);
		r=s;
		reverse(r.begin(),r.end());
		r=rot180(r);
		cout<<s<<" ";
		if(areEqual(s,r)){
			cout<<"(is)"<<'\n';
		}else{
			cout<<"(not)"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/