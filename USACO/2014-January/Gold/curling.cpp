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

struct Point{
    long long x,y;
};

bool cmp(Point a,Point b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	return a.x<b.x;
}

#define maxN 50005

long long N;
//group 1 of polong longs
vector<Point> grp1;
//group 2 of polong longs
vector<Point> grp2;
long long result[2];

//counter clockwise
bool ccw(Point a,Point b,Point c){
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))>=0;
}

//top convex hull
vector<Point> solveTop(vector<Point> arr){
	//sort(arr.begin(),arr.end(),cmp2);
	vector<Point> ans;
	for(long long i=0;i<arr.size();i++){
		ans.push_back(arr[i]);
		if(ans.size()<3) continue;

		while(ans.size()>=3&&ccw(ans[ans.size()-3],ans[ans.size()-2],ans[ans.size()-1])){
			ans.pop_back();
			ans.pop_back();
			ans.push_back(arr[i]);
		}
	}
	return ans;
}

//clockwise
bool cw(Point a,Point b,Point c){
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))<=0;
}

//bottom convex hull
vector<Point> solveBottom(vector<Point> arr){
	vector<Point> ans;
	for(long long i=0;i<arr.size();i++){
		ans.push_back(arr[i]);
		if(ans.size()<3) continue;

		while(ans.size()>=3&&cw(ans[ans.size()-3],ans[ans.size()-2],ans[ans.size()-1])){
			ans.pop_back();
			ans.pop_back();
			ans.push_back(arr[i]);
		}
	}
	return ans;
}

//calculates slope
double slope(Point a, Point b){
	return (double)(b.y-a.y)/(double)(b.x-a.x);
}

//puts line long longo polong long slope form and checks if above or below
//1 means above
//0 means ontop
//-1 means below
long long lineS(Point n,Point a,Point b){
	double ny;
	if(a.x!=b.x) ny=(slope(a,b)*((double)n.x-(double)a.x))+(double)a.y;
	else if((n.y>a.y&&n.y>b.y)||(n.y<a.y&&n.y<b.y)) return -2;
	else return 0;
	if((double)n.y>ny) return 1;
	if((double)n.y==ny) return 0;
	return -1;
}

/*
//this method is just used to make output easier
string cP(Point a){
	return to_string(a.x)+" "+to_string(a.y);
}
*/

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("curling.in");
	ofstream cout("curling.out");
	cin>>N;
	grp1.resize(N);
	grp2.resize(N);
	for(long long i=0;i<N;i++){
		cin>>grp1[i].x>>grp1[i].y;
	}
	for(long long i=0;i<N;i++){
		cin>>grp2[i].x>>grp2[i].y;
	}
	sort(grp1.begin(),grp1.end(),cmp);
	sort(grp2.begin(),grp2.end(),cmp);

	//first solve for groups1s polong longs
	for(long long z=0;z<2;z++){
		vector<Point> topCH=solveTop(grp1);
		vector<Point> bottomCH=solveBottom(grp1);
		/*
		cout<<"Round:"<<z<<endl;
		cout<<"TOP:"<<endl;
		for(Point a:topCH){
			cout<<cP(a)<<" ";
		}
		cout<<endl;
		cout<<"BOTTOM:"<<endl;
		for(Point a:bottomCH){
			cout<<cP(a)<<" ";
		}
		cout<<endl;
		*/

	//topR finds right polong long on line on top hull within x range of current polong long
	//bottomR find right polong long on line on bottom hull within x range of current polong long
		for(long long i=0;i<grp2.size();i++){
			auto topR=lower_bound(topCH.begin(),topCH.end(),grp2[i],cmp);
			auto bottomR=lower_bound(bottomCH.begin(),bottomCH.end(),grp2[i],cmp);
			//if(topR==topCH.begin()||topR==topCH.end()||bottomR==bottomCH.begin()||bottomR==bottomCH.end()) continue;
			//these variables below find whether polong long is above,on,or below
			if((*prev(topR)).x<=grp2[i].x&&grp2[i].x<=(*topR).x&&(*prev(bottomR)).x<=grp2[i].x&&grp2[i].x<=(*bottomR).x){
				long long locTop=lineS(grp2[i],*prev(topR),*topR);
				long long locBottom=lineS(grp2[i],*prev(bottomR),*bottomR);
				if(locTop==-2||locBottom==-2) continue;
				//cout<<locBottom<<" "<<locTop<<" caused by "<<cP(grp2[i])<<" between top: "<<cP(*prev(topR))<<" , "<<cP(*topR)<<" and bottom: "<<cP(*prev(bottomR))<<" , "<<cP(*bottomR)<<endl;
				if((locTop!=locBottom)||(locTop==locBottom&&locTop==0)){
					result[z]++;
				}
			}
		}

		swap(grp1,grp2);
	}
	cout<<result[0]<<" "<<result[1]<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/