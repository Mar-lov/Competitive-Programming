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
	int e1[2];
	int e2[2];
	int g1[2];
	int g2[2];
	cin>>g1[0]>>g1[1]>>g2[0]>>g2[1];
	cin>>e1[0]>>e1[1]>>e2[0]>>e2[1];
	int ew=0;
	int gw=0;
	for(int fd=e1[0];fd<=e1[1];fd++){
		for(int sd=e2[0];sd<=e2[1];sd++){
			for(int td=g1[0];td<=g1[1];td++){
				for(int qd=g2[0];qd<=g2[1];qd++){
					if(fd+sd>td+qd){
						ew++;
					}else if(fd+sd<td+qd){
						gw++;
					}
				}
			}
		}
	}
	if(ew>gw){
		cout<<"Emma"<<'\n';
	}else if(ew<gw){
		cout<<"Gunnar"<<'\n';
	}else{
		cout<<"Tie"<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/