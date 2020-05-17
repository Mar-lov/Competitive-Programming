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




int main() {
	double A,B,C;
	string s;
	char op;
	double ans;
	while(cin>>A>>B>>s>>C){
		if(s=="POWER"){
			ans=pow(A,B);
			op='^';
		}else if(s=="MULTIPLY"){
			ans=A*B;
			op='*';
		}else if(s=="DIVIDE"){
			ans=A/B;
			op='/';
		}else if(s=="ADD"){
			ans=A+B;
			op='+';
		}else if(s=="SUBTRACT"){
			ans=A-B;
			op='-';
		}
		cout<<fixed;
		ans=round(10*ans)/10.0;
		if(ans==C){
			cout<<setprecision(1)<<C<<" is correct for "<<A<<" "<<op<<" "<<B<<'\n';
		}else{
			cout<<setprecision(1)<<A<<" "<<op<<" "<<B<<" = "<<ans<<", not "<<C<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/