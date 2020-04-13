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
	int n,m;
	cin>>n>>m;
	while(!(n==0&&m==0)){
		int count =0;
		int p[n];
		for(int i=0;i<n;i++){
			p[i]=i;
		}
		int c[m][3];	
		for(int i=0;i<m;i++){
			cin>>c[i][0]>>c[i][1]>>c[i][2];
		}
		do{
			bool pos=true;
			for(int i=0;i<m;i++){
				if(c[i][2]>0){
					if(abs(p[c[i][1]]-p[c[i][0]])>c[i][2]) pos=false;
				}else if(c[i][2]<0){
					if(abs(p[c[i][1]]-p[c[i][0]])<abs(c[i][2])) pos=false;
				}
			}
			if(pos) count++;
		}while(next_permutation(p,p+n));
		cout<<count<<'\n';
		cin>>n>>m;
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/