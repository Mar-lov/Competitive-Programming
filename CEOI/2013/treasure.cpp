/*
Code by @marlov       
*/
#include "treasure.h"
//#include <iostream>
//using namespace std;
#define maxN 105
 
int N;
int psum[maxN][maxN];

//countTreasure(x1+1,y1+1,x2,y2);
//Report( x1,y1);
/*
int countTreasure(int x1,int y1,int x2,int y2){
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int x;
	cin>>x;
	return x;
}
*/

void findTreasure(int givenN){
//	ios_base::sync_with_stdio(0); cin.tie(0);
    N=givenN;
	int mid=((N+1)/2.0);
	for(int i=mid;i<=N;i++){
		for(int j=mid;j<=N;j++){
			psum[i][j]=countTreasure(1,1,i,j);
		}
	}
	for(int i=1;i<mid;i++){
		for(int j=mid;j<=N;j++){
			psum[i][j]=psum[N][j]-countTreasure(i+1,1,N,j);
		}
	}
	for(int i=mid;i<=N;i++){
		for(int j=1;j<mid;j++){
			psum[i][j]=psum[i][N]-countTreasure(1,j+1,i,N);
		}
	}
	for(int i=1;i<mid;i++){
		for(int j=1;j<mid;j++){
			psum[i][j]=-(psum[N][N]-countTreasure(i+1,j+1,N,N)-psum[i][N]-psum[N][j]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(psum[i][j]-psum[i-1][j]-psum[i][j-1]+psum[i-1][j-1]==1) Report(i,j);
		}
	}
}


/*
int main(){
//	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N;
	for(int i=mid;i<=N;i++){
		for(int j=mid;j<=N;j++){
			psum[i][j]=countTreasure(1,1,i,j);
		}
	}
	for(int i=1;i<mid;i++){
		for(int j=mid;j<=N;j++){
			psum[i][j]=psum[N][j]-countTreasure(i+1,1,N,j);
		}
	}
	for(int i=mid;i<=N;i++){
		for(int j=1;j<mid;j++){
			psum[i][j]=psum[i][N]-countTreasure(1,j+1,i,N);
		}
	}
	for(int i=1;i<mid;i++){
		for(int j=1;j<mid;j++){
			psum[i][j]=-(psum[N][N]-countTreasure(i+1,j+1,N,N)-psum[i][N]-psum[N][j]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(psum[i][j]-psum[i-1][j]-psum[i][j-1]+psum[i-1][j-1]==1) cout<<i<<" "<<j<<endl;
		}
	}
}
*/
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/