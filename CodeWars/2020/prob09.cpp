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
	int m,s;
	cin>>m>>s;
	while(!(m==0&&s==0)){
		int ts=m*60+s;
		int sl=abs(3000-ts);
		int sn=sl%60;
		int mn=(sl-sn)/60;
		if(ts>3000){
			cout<<"Time remaining -"<<mn<<" minutes and -"<<sn<<" seconds (we're gonna need a bigger record)"<<'\n';
		}else if(ts>1500){
			cout<<"Time remaining "<<mn<<" minutes and "<<sn<<" seconds (we'll need both sides)"<<'\n';
		}else{
			cout<<"Time remaining "<<mn<<" minutes and "<<sn<<" seconds"<<'\n';
		}
		cin>>m>>s;
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/