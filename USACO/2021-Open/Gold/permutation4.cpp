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
typedef pair<long long,long long> ii;

#define maxN 20
#define MOD 1000000007

long long add(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long sum=a+b;
	sum%=MOD;
	return sum;
}
long long sub(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long dif=a-b;
	if(dif<0) dif+=MOD;
	dif%=MOD;
	return dif;
}
long long mult(long long a,long long b){
	a%=MOD;
	b%=MOD;
	long long prod=a*b;
	prod%=MOD;
	return prod;
}
struct Point{
	long long x,y;
};

struct Comb{
	long long p[3];
};

long long N;
Point pts[maxN];
long long result=0;
long long dp[(1<<maxN)];
Comb has[(1<<maxN)];

double area(Point a,Point b,Point c){
	return .5*abs( ((a.x*b.y)+(b.x*c.y)+(c.x*a.y))-((a.y*b.x)+(b.y*c.x)+(c.y*a.x)) );
}

//find if inside by using area
bool inside(Comb a,long long i){
	if(a.p[0]==i||a.p[1]==i||a.p[2]==i) return false;
	double org=area(pts[a.p[0]],pts[a.p[1]],pts[a.p[2]]);
	double a1=area(pts[i],pts[a.p[1]],pts[a.p[2]]);
	double a2=area(pts[a.p[0]],pts[i],pts[a.p[2]]);
	double a3=area(pts[a.p[0]],pts[a.p[1]],pts[i]);
	return org==(a1+a2+a3);
}
bool outside(Comb a,long long i){
	if(a.p[0]==i||a.p[1]==i||a.p[2]==i) return false;
	return !inside(a,i);
}

long long works(Comb a,long long i){
	long long ans=-1;
	Comb temp=a;
	temp.p[0]=i;
	if(inside(temp,a.p[0])) ans=0;
	temp.p[0]=a.p[0];
	temp.p[1]=i;
	if(inside(temp,a.p[1])) ans=1;
	temp.p[1]=a.p[1];
	temp.p[2]=i;
	if(inside(temp,a.p[2])) ans=2;
	temp.p[2]=a.p[2];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>pts[i].x>>pts[i].y;
	}
	if(N>maxN){
		cout<<0<<endl;
		return 0;
	}
	for(long long i=1;i<(1<<N);i++){
		long long on=0;
		Comb cur;
		for(long long j=0;j<N;j++){
			if(i&(1<<j)){
				if(on<3) cur.p[on]=j;
				on++;
			}
		}
		if(on>3) continue;
		if(on==1) dp[i]=1;
		if(on==2) dp[i]=2;
		if(on==3) dp[i]=6;
		has[i]=cur;
	}

	for(long long i=0;i<(1<<N);i++){
		long long on=0;
		for(long long j=0;j<N;j++){
			if(i&(1<<j)) on++;
		}
		if(on<3) continue;
		
		for(long long j=0;j<N;j++){
			if(i&(1<<j)) continue;
			if(inside(has[i],j)){
				dp[i|(1<<j)]=add(dp[i|(1<<j)],dp[i]);
			}else if(outside(has[i],j)){
				//cout<<has[i].p[0]<<" "<<has[i].p[1]<<" "<<has[i].p[2]<<" with "<<j<<endl;
				long long wv=works(has[i],j);
				if(wv!=-1){
					dp[i|(1<<j)]=add(dp[i|(1<<j)],dp[i]);
					Comb temp=has[i];
					temp.p[wv]=j;
					has[i|(1<<j)]=temp;
					//cout<<has[i].p[0]<<" "<<has[i].p[1]<<" "<<has[i].p[2]<<" with "<<j<<endl;
				}
			}
		}
		
	}
	cout<<dp[(1<<N)-1]<<endl;
	
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/