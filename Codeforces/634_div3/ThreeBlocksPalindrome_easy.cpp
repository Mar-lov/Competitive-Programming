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

int psum[26][2005];


int main() {
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<26;i++){
			for(int j=0;j<2005;j++){
				psum[i][j]=0;	
			}
		}
		int n;
		cin>>n;
		int cur;
		for(int i=1;i<=n;i++){
			cin>>cur;
			cur--;
			for(int j=0;j<26;j++){
				psum[j][i]=(psum[j][i-1])+(cur==j?1:0);
			}
		}
		int mtl=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int ms=0;
				int mm=0;
				for(int k=0;k<26;k++){
					//j-1 maybe negetive
					ms=max(ms,min(psum[k][i-1],psum[k][n]-psum[k][j]));
					mm=max(mm,psum[k][j]-psum[k][i-1]);
				}
				mtl=max(mtl,mm+2*ms);
				//cout<<i<<" "<<j<<" "<<mm<<" "<<ms<<'\n';				
			}
		}
		cout<<mtl<<'\n';
		
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/