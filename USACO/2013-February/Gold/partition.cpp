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

#define maxN 15
#define INF 1000000000
int N,K;
int arr[maxN][maxN];
int result=INF;

int solve(int b,int m){
	int need=0;
	vector<int> tv(N,0);
	for(int i=0;i<N;i++){
		int ci=-1;
		vector<int> sum;
		for(int j=0;j<N;j++){
			if(b&(1<<j)){
				ci++;
				sum.push_back(0);
			}
			sum[ci]+=arr[j][i];
			if(sum[ci]>m) return INF;
		}
		for(int i=0;i<sum.size();i++){
			tv[i]+=sum[i];
			if(tv[i]>m){
				tv=sum;
				need++;
				break;
			}
		}
	}
	return need;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("partition.in");
	ofstream cout("partition.out");
	cin>>N>>K;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}

	for(int p=1;p<pow(2,N);p++){
		if((p&(1<<0))==0) continue;
		int used=0;
		for(int i=0;i<N;i++){
			if(p&(1<<i)) used++;
		}
		used--;
		int a=0;
		//randomly chose value till it worked
		int b=50000;
		while(a<b){
			int mid=(a+b)/2;
			if(solve(p,mid)<=(K-used)){
				b=mid;
			}else{
				a=mid+1;
			}
		}
		//cout<<p<<" "<<a<<'\n';
		result=min(result,a);
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/