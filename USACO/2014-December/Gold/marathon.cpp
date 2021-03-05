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

#define maxN 100005

int N,Q;
pair<int,int> arr[maxN];

int dist(int a,int b){
	return abs(arr[a].first-arr[b].first)+abs(arr[a].second-arr[b].second);
}

int stree[4*maxN];

void supdate(int index,int L,int R,int loc){
	if(L==R){
		stree[index]=0;
		return;
	}
	if(L<=loc&&loc<=(L+R)/2) supdate(2*index,L,(L+R)/2,loc);
	if(((L+R)/2+1)<=loc&&loc<=R) supdate(2*index+1,(L+R)/2+1,R,loc);
	stree[index]=stree[2*index]+dist((L+R)/2,(L+R)/2+1)+stree[2*index+1];
}
int squery(int index,int qL,int qR,int L,int R){
	if(R<qL||qR<L) return 0;
	if(qL<=L&&R<=qR){
		if(R!=qR){
			return stree[index]+dist(R,R+1);
		}else{
			return stree[index];
		}
	}
	return squery(2*index,qL,qR,L,(L+R)/2)+squery(2*index+1,qL,qR,(L+R)/2+1,R);
}


int mtree[4*maxN];
void mupdate(int index,int L,int R,int loc){
	if(L==R){
		if(L==0||L==N-1){
			mtree[index]=0;
			return;
		}
		mtree[index]=dist(L-1,R+1)-(dist(L-1,L)+dist(R,R+1));
		//cout<<"For "<<L<<" new dist ="<<dist(L-1,R+1)<<" while old equals "<<(dist(L-1,L)+dist(R,R+1))<<'\n';
		return ;
	}
	if(L<=loc&&loc<=(L+R)/2) mupdate(2*index,L,(L+R)/2,loc);
	if(((L+R)/2+1)<=loc&&loc<=R) mupdate(2*index+1,(L+R)/2+1,R,loc);
	mtree[index]=min(mtree[2*index],mtree[2*index+1]);
}

int mquery(int index,int qL,int qR,int L,int R){
	if(R<qL||qR<L) return 0;
	if(qL<=L&&R<=qR) return mtree[index];
	return min(mquery(2*index,qL,qR,L,(L+R)/2),mquery(2*index+1,qL,qR,(L+R)/2+1,R));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("marathon.in");
	ofstream cout("marathon.out");
	cin>>N>>Q;
	for(int i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	for(int i=0;i<N;i++){
	supdate(1,0,N-1,i);
	}
	for(int i=0;i<N;i++){
	mupdate(1,0,N-1,i);
	}
	char ca;
	for(int z=0;z<Q;z++){
		cin>>ca;

		if(ca=='Q'){
			int I,J;
			cin>>I>>J;
			I--;
			J--;
			cout<<squery(1,I,J,0,N-1)+mquery(1,I+1,J-1,0,N-1)<<'\n';
			//cout<<"sum:"<<squery(1,I,J,0,N-1)<<" and min:"<<mquery(1,I+1,J-1,0,N-1)<<'\n';
		}else if(ca=='U'){
			int I,X,Y;
			cin>>I>>X>>Y;
			I--;
			arr[I]=make_pair(X,Y);
			supdate(1,0,N-1,I);
			if(I>0) mupdate(1,0,N-1,I-1);
			mupdate(1,0,N-1,I);
			if(I<N-1) mupdate(1,0,N-1,I+1);
			//for(int i=0;i<N;i++){
			//	cout<<mquery(1,i,i,0,N-1)<<'\n';
			//}
		}

	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/