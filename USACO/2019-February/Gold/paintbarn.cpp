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

const int maxG=202;
int N,K;
int ans=0;
int wall[maxG][maxG];
int actual[maxG][maxG];

int main() {
	cin>>N>>K;
	int a,b,c,d;
	for(int i=0;i<N;i++){
		cin>>a>>b>>c>>d;
		a++;b++;c++;d++;
		for(int j=a;j<c;j++){
			wall[j][b]++;
			wall[j][d]--;
		}
	}
	for(int i=1;i<maxG;i++){
		int delta=0;
		for(int j=1;j<maxG;j++){
			delta+=wall[i][j];
			wall[i][j]=delta;
			if(wall[i][j]==K-1) actual[i][j]=1;
			if(wall[i][j]==K){
				 ans++;
				actual[i][j]=-1;
			}
		}
	}
	for(int i=1;i<maxG;i++){
		for(int j=1;j<maxG;j++){
			actual[i][j]+=actual[i-1][j];
			actual[i][j]+=actual[i][j-1];
			actual[i][j]-=actual[i-1][j-1];
		}
	}
	//for(int )
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/