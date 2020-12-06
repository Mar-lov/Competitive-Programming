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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

string s;
int lp=0;
int rp=0;
int result=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("clumsy.in");
    ofstream cout("clumsy.out");
	getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            lp++;
        }else if(s[i]==')'){
            rp++;
            if(lp>0){
                rp--;
                lp--;
            }
        }
    }
    result+=lp/2;
    lp%=2;
    result+=rp/2;
    rp%=2;
    if(lp==1&&rp==1){
        result+=2;
    }
    cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/