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
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

long long count_rectangles(vector< vector<int> > a){
	int N=a.size();
	int M=a[0].size();
	int result=0;

	bool rows[N][M][M];
	bool cols[M][N][N];
	for(int i=1;i<N-1;i++){
		for(int j=1;j<M-1;j++){
			int cm=0;
			for(int k=j;k<M-1;k++){
				cm=max(cm,a[i][k]);
				if(cm<a[i][j-1]&&cm<a[i][k+1]) rows[i][j][k]=true;
				else rows[i][j][k]=false;
			}
		}
	}

	for(int i=1;i<M-1;i++){
		for(int j=1;j<N-1;j++){
			int cm=0;
			for(int k=j;k<N-1;k++){
				cm=max(cm,a[k][i]);
				if(cm<a[j-1][i]&&cm<a[k+1][i]){
					cols[i][j][k]=true;
					//cout<<"cols:"<<i<<" "<<j<<" "<<k<<" "<<a[k][i]<<endl;
				}else{
					cols[i][j][k]=false;
				}
			}
		}
	}

	for(int i=1;i<N-1;i++){
		for(int j=1;j<M-1;j++){
			for(int k=j;k<M-1;k++){
				for(int x=i;x<N-1;x++){
					if(!rows[x][j][k]) break;
					bool pos=true;
					for(int y=j;y<=k;y++){
						if(!cols[y][i][x]) pos=false;
					}
					//if (pos) cout<<i<<" "<<x<<" "<<j<<" "<<k<<endl;
					if(pos) result++;
				}
			}
		}
	}
	
return result;

}
/*
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<count_rectangles( {{4, 8, 7, 5, 6},{7, 4, 10, 3, 5},{9, 7, 20, 14, 2},{9, 14, 7, 3, 6},{5, 7, 5, 2, 7},{4, 5, 13, 5, 6}} );
    return 0;
}
*/


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/