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

#define maxN 44
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

long long factorial[maxN];

struct Point{
	long long x,y;
};

struct Comb{
	long long p[3];
	long long in;
	long long out;
	long long ans;
};

long long N;
Point pts[maxN];
vector<Comb> vals;
vector< ii > order;
long long toIndex[maxN][maxN][maxN];
long long result=0;

//shoelace
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

long long totalInside(Comb a){
	long long ans=0;
	for(long long i=0;i<N;i++){
		if(inside(a,i)) ans++;
	}
	return ans;
}

long long totalOutside(Comb a){
	long long ans=0;
	for(long long i=0;i<N;i++){
		if(outside(a,i)) ans++;
	}
	return ans;
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

	//precompute factorial
	factorial[0]=1;
	for(long long i=1;i<maxN;i++){
		factorial[i]=mult(i,factorial[i-1]);
	}

	//read in polong longs
	cin>>N;
	for(long long i=0;i<N;i++){
		cin>>pts[i].x>>pts[i].y;
	}
	//create all combinations
	long long tc=0;
	long long a=0,b=1,c=2;
	while((a+2<N)){
		Comb nC;
		nC.p[0]=a;
		nC.p[1]=b;
		nC.p[2]=c;
		nC.in=totalInside(nC);
		nC.out=totalOutside(nC);
		//NEED TO SET CORRECT INITIAL
		nC.ans=mult(factorial[3],factorial[nC.in]);
		//PLEZ
		vals.push_back(nC);
		order.push_back(make_pair(nC.in,tc));
		toIndex[nC.p[0]][nC.p[1]][nC.p[2]]=tc;
		tc++;
		//cout<<a+1<<" "<<b+1<<" "<<c+1<<" inside:"<<nC.in<<endl;
		//permut
		c++;
		if(c>=N){
			b++;
			c=b+1;
		}
		if(b+1>=N){
			a++;
			b=a+1;
			c=b+1;
		}
	}

	sort(order.begin(),order.end());

	for(long long i=0;i<order.size();i++){
		long long ci=order[i].second;
		for(long long i=0;i<N;i++){
			//only check outside
			if(outside(vals[ci],i)){
				long long rv=works(vals[ci],i);
				if(rv!=-1){
					Comb temp=vals[ci];
					temp.p[rv]=i;
					sort(temp.p,temp.p+3);
					long long ti=toIndex[temp.p[0]][temp.p[1]][temp.p[2]];
					//cout<<rv<<": "<<vals[ci].p[0]+1<<" "<<vals[ci].p[1]+1<<" "<<vals[ci].p[2]+1<<" open to "<<temp.p[0]+1<<" "<<temp.p[1]+1<<" "<<temp.p[2]+1<<endl;
					//NEED TO FIND CORRECT PROP
					vals[ti].ans=add(vals[ti].ans,mult(vals[ci].ans,factorial[vals[ti].in-vals[ci].in-1]));

					//PLEZ
				}
			}
		}
		if(vals[ci].out==0) result=vals[ci].ans;
	}
	/*
	for(long long i=0;i<vals.size();i++){
		cout<<vals[i].ans<<endl;
	}
*/
	cout<<result%MOD<<endl;
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/