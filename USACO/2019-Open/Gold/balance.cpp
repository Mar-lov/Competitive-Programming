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
typedef pair<ll,ll> pi;

#define maxN 100005

int N;
int arr[2*maxN];
int result=100000000;

int inversions(int a,int b){
	int cv=0;
	int t0=0;
	for(int i=b;i>=a;i--){
		if(arr[i]==0) t0++;
		else cv+=t0;
	}
	return cv;
}

void right(){
	int r1;
	int l0;
	int t1=0;
	int t0=0;
	for(int i=0;i<N;i++) if(arr[i]==1){r1=i;t1++;}
	for(int i=2*N-1;i>=N;i--) if(arr[i]==0){l0=i;t0++;}
	int lv=inversions(0,N-1);
	int rv=inversions(N,2*N-1);
	result=min(abs(lv-rv),result);
	int t=0;
	while(r1>=0&&l0<2*N){
		t+=abs(l0-r1);
		lv-=(N-1-r1);
		t1--;
		lv+=t1;
		rv+=(l0-N-1);
		t0--;
		rv+=t0;
		r1--;
		while(r1>=0&&arr[r1]!=1) r1--;
		l0++;
		while(l0<2*N&&arr[l0]!=0) l0++;
		result=min(result,t+abs(lv-rv));
	}
}

void left(){
	int r0;
	int l1;
	int t0=0;
	int t1=0;
	for(int i=0;i<N;i++) if(arr[i]==0){r0=i;t0++;}
	for(int i=2*N-1;i>=N;i--) if(arr[i]==1){l1=i;t1++;}
	int lv=inversions(0,N-1);
	int rv=inversions(N,2*N-1);
	result=min(result,abs(lv-rv));
	int t=0;
	while(l1<2*N&&r0>=0){
		t+=abs(r0-l1);
		lv-=(N-t0);
		t0--;
		rv-=(N-t1-(l1-N));
		t1--;
		r0--;
		while(r0>=0&&arr[r0]!=0) r0--;
		l1++;
		while(l1<2*N&&arr[l1]!=1) l1++;
		result=min(result,t+abs(lv-rv));
	}
}

int main() {
	ifstream cin("balance.in");
	ofstream cout("balance.out");
	cin>>N;
	for(int i=0;i<2*N;i++){
		cin>>arr[i];
	}
	right();
	left();
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/