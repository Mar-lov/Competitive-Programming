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
	int t;
	cin>>t;
	while(t--){
		int A,B,C;
		cin>>A>>B>>C;
		int found=0;
		for(int a=-100;a<=100&&found==0;a++){
			for(int b=-100;b<=100&&found==0;b++){
				for(int c=-100;c<=100&&found==0;c++){
					if(a!=b&&a!=c&&b!=c){
					if(pow(a,2)+pow(b,2)+pow(c,2)==C){
						if(a*b*c==B){
							if(a+b+c==A){
								cout<<a<<" "<<b<<" "<<c<<'\n';
								found++;
							}
						}
					}
					}
				}
			}
		}
		if(found==0) cout<<"No solution."<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/