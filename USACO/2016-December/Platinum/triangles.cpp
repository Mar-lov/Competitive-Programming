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
typedef pair<double,double> pi;

int N;
pi pts[305];
int ctn[305][305];
int ans[305];
double X(pi a){
	return a.first;
}
double Y(pi a){
	return a.second;
}
bool below(int a,int b){
	if(X(pts[a])==X(pts[b])&&Y(pts[a])>=Y(pts[b])) return true;
	return false;
}

double slope(pi a,pi b){
	return (double)(Y(b)-Y(a))/(double)(X(b)-X(a));
}

bool belowBoth(int a,int b,int c){
	
	if(X(pts[a])<X(pts[c])&&X(pts[c])<X(pts[b])&&(Y(pts[c])<slope(pts[a],pts[b])*(X(pts[c])-X(pts[a]))+Y(pts[a])) ) return true;
	else if(X(pts[b])<X(pts[c])&&X(pts[c])<X(pts[a])&&(Y(pts[c])<slope(pts[a],pts[b])*(X(pts[c])-X(pts[a]))+Y(pts[a])) ) return true;
	return false;
}

int main() {
	ifstream cin("triangles.in");
	ofstream cout("triangles.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>pts[i].first>>pts[i].second;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(X(pts[i])<X(pts[j])){
				for(int k=0;k<N;k++){
					if(k!=i&&k!=j){
						if(below(i,k)) ctn[i][j]++;
						if(below(j,k)) ctn[i][j]++;
						if(belowBoth(i,j,k)) ctn[i][j]+=2;
					}
				}
				ctn[j][i]=-1*ctn[i][j];
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<j;k++){
				int temp=abs(ctn[i][j]+ctn[j][k]+ctn[k][i])/2;
				temp-=belowBoth(i,j,k);
				temp-=belowBoth(j,k,i);
				temp-=belowBoth(k,i,j);
				ans[temp]++;
			}
		}
	}
	for(int i=0;i<N-2;i++){
		cout<<ans[i]<<'\n';
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/