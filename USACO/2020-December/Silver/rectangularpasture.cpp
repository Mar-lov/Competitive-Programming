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

#define maxN 2505

int N;
pair<int,int> arr[maxN];
int lower[maxN][maxN];
int higher[maxN][maxN];
//account for empty set
long long result=1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr+1,arr+N+1);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i].second<arr[j].second) higher[i][j]++;
			higher[i][j]+=higher[i][j-1];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i].second>arr[j].second) lower[i][j]++;
			lower[i][j]+=lower[i][j-1];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			long long hy=0;
			long long ly=0;
			if(arr[i].second>=arr[j].second){
				hy=higher[i][j]-higher[i][i];
				ly=lower[j][j]-lower[j][i];
			}else{
				hy=higher[j][j]-higher[j][i];
				ly=lower[i][j]-lower[i][i];
			}
			//cout<<"("<<i<<","<<j<<") ="<<ly<<"*"<<hy<<"="<<(hy+1)*(ly+1)<<'\n';
			result+=1*(1+hy)*(1+ly);
		}
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/