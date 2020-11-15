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
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int N;
double R,B,M;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	while(N--){
		cin>>R>>B>>M;
		int nm=1201;
		for(int i=1;i<=1200;i++){
			double MI=B*(R/100.0);
			MI*=100.0;
			MI=round(MI);
			MI/=100.0;
			B+=MI;
			B-=M;
			//cout<<B<<'\n';
			if(B<=0.000000001){
				nm=i;
				break;
			}
		}
		if(nm<=1200){
			cout<<nm<<'\n';
		}else{
			cout<<"impossible"<<'\n';
		}
	}
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/