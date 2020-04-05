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
	int n;
	cin>>n;
	cout<<setfill('0');
	while(n!=0){
		int found =0;
		for(int den=01234;den<=98765/n;den++){
			int num=den*n;
			int ctn=(num<10000||den<10000?1:0);
			string val=to_string(num)+to_string(den);
			for(int i=0;i<val.length();i++){
				ctn|=1<<(val[i]-'0');
			}
			if(ctn==pow(2,10)-1){
				cout<<setw(5)<<num;
				cout<<" / ";
				cout<<setw(5)<<den;
				cout<<" = "<<n<<'\n';
				found++;
			}
		}
		if(found==0){
			cout<<"There are no solutions for "<<n<<".\n";
		}
		cin>>n;
		if(n!=0) cout<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/