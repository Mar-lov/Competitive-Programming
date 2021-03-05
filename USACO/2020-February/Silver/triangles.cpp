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
typedef pair<long long,long long> pi;

#define maxN 100005
#define MOD 1000000007

struct pts{
	int x,y;
	int xl;
	int xr;
	int yd;
	int yu;

};

bool cmpy(pts a,pts b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
bool cmpx(pts a,pts b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int N;
pts arr[maxN];
int result=0;
int cg=1;

long long add(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long sum=a+b;
	sum%=MOD;
	return sum;

}
long long subtract(long long a,long long b){
	 a%=MOD;
	 b%=MOD;
	 int difference=a-b;
	 if(difference<0) difference+=MOD;
	 difference%=MOD;
	 return difference;
}
long long multiply(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long product=a*b;
	product%=MOD;
	return product;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("triangles.in");
	ofstream cout("triangles.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i].x>>arr[i].y;
		arr[i].x+=10000;
		arr[i].y+=10000;
		arr[i].xl=0;
		arr[i].xr=0;
		arr[i].yu=0;
		arr[i].yd=0;
	}
	sort(arr,arr+N,cmpx);
	cg=1;
	for(int i=1;i<N;i++){
		if(arr[i].x==arr[i-1].x){
			arr[i].yd=add(arr[i].yd,arr[i-1].yd);
			arr[i].yd=add(arr[i].yd,multiply(subtract(arr[i].y,arr[i-1].y),cg));
			cg++;
		}else{
			cg=1;
		}
	}
	cg=1;
	for(int i=N-2;i>=0;i--){
		if(arr[i].x==arr[i+1].x){
			arr[i].yu=add(arr[i].yu,arr[i+1].yu);
			arr[i].yu=add(arr[i].yu,multiply(subtract(arr[i+1].y,arr[i].y),cg));
			cg++;
		}else{
			cg=1;
		}
	}
	sort(arr,arr+N,cmpy);
	cg=1;
	for(int i=1;i<N;i++){
		if(arr[i].y==arr[i-1].y){
			arr[i].xl=add(arr[i].xl,arr[i-1].xl);
			arr[i].xl=add(arr[i].xl,multiply(subtract(arr[i].x,arr[i-1].x),cg));
			cg++;
		}else{
			cg=1;
		}
	}
	cg=1;
	for(int i=N-2;i>=0;i--){
		if(arr[i].y==arr[i+1].y){
			arr[i].xr=add(arr[i].xr,arr[i+1].xr);
			arr[i].xr=add(arr[i].xr,multiply(subtract(arr[i+1].x,arr[i].x),cg));
			cg++;
		}else{
			cg=1;
		}
	}
	for(int i=0;i<N;i++){
		//cout<<arr[i].xl<<" "<<arr[i].xr<<" & "<<arr[i].yd<<" "<<arr[i].yu<<'\n';
		result=add(result,multiply(add(arr[i].xl,arr[i].xr),add(arr[i].yd,arr[i].yu)));
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/