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

int N;
int arr[102][102];
int maxS=0;

int sumUp(int a,int b,int x,int y){
	return arr[x][y]-arr[a-1][y]-arr[x][b-1]+arr[a-1][b-1];
}
int main() {
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=2;i<=N;i++){
		arr[1][i]+=arr[1][i-1];
		arr[i][1]+=arr[i-1][1];
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			arr[i][j]=arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
		}
	}
	for(int a=1;a<=N;a++){
		for(int b=1;b<=N;b++){
			//cout<<arr[a][b]<<" ";
			for(int x=a;x<=N;x++){
				for(int y=b;y<=N;y++){
					maxS=max(maxS,sumUp(a,b,x,y));
				}
			}
		}
	}
	cout<<maxS<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/