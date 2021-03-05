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
#include "prize.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int N;
int sN;
int mvs=0;
int result=-1;

/*
vector<int> ask(int i){
	cout<<"query: "<<i<<endl;
	int rlv,rrv;
	cin>>rlv>>rrv;
	return {rlv,rrv};
}
*/

unordered_map<int,int> lv;
unordered_map<int,int> rv;
vector<int> query(int i){
	if(!(lv.count(i)==1&&rv.count(i)==1)){
	vector<int> askv=ask(i);
	lv[i]=askv[0];
	rv[i]=askv[1];
	}
	if(lv[i]+rv[i]==0) result=i;
	return {lv[i],rv[i]};
}

void binary_search(int l,int r){
	//cout<<"seeing:"<<l<<","<<r<<endl;
	if(result!=-1) return;
	if(l+1>=r) return;
	vector<int> lv=query(l);
	vector<int> rv=query(r);
	int mid=(l+r)/2;
	vector<int> midv=query(mid);
	while(midv[0]+midv[1]<mvs){
		mid++;
		midv=query(mid);
	}
	if(mid==r) return;
	if(result!=-1) return;
	if(midv[0]-lv[0]!=0) binary_search(l,mid);
	if(result!=-1) return;
	if(rv[0]-midv[0]!=0) binary_search(mid,r);
}

//method can use int[] ask(int i) which return left and right value
int find_best(int n){
	int N=n;
	int sN=floor(sqrt((double)N));
	//loop first sqrtN value to find max dude
	for(int i=0;i<N;i+=sN){
		vector<int> qv=query(i);
		mvs=max(mvs,qv[0]+qv[1]);
	}
	if(result!=-1) return result;
	//loop through sqrtN
	int cl=0;
	int cr=sN;
	vector<int> clv;
	vector<int> crv;
	while(cr<N&&result==-1){
		clv=query(cl);
		if(clv[0]+clv[1]<mvs){
			cl++;
			continue;
		}
		crv=query(cr);
		if(cr<N&&crv[0]+crv[1]<mvs){
			cr++;
			continue;
		}
		if(crv[0]-clv[0]!=0) binary_search(cl,cr);
		swap(cl,cr);
		cr=cl+sN;
	}
	if(result!=-1) return result;
	cr=N-1;
	vector<int> lastV=query(cr);
	while(cr>cl&&lastV[0]+lastV[1]<mvs&&result==-1){
		cr--;
		lastV=query(cr);
	}
	if(lastV[0]-crv[0]!=0&&result==-1) binary_search(cl,cr);
	
	return result;
}


/*
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int val=find_best(8);
	cout<<"ANSWER:"<<val<<endl;	
    return 0;
}
*/

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
	* long long
*/