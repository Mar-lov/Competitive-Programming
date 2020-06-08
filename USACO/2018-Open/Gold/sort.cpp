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
#include <iterator>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

#define maxN 100013

pair<int,int> arr[maxN];
int result=1;
int N, ft[100013];
void update(int x, int v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
int query (int x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}

int main() {
	ifstream cin("sort.in");
	ofstream cout("sort.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i].first;
		arr[i].second=i+1;
	}
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		update(arr[i].second,1);
		result=max(result,(i+1)-query(i+1));
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/