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

#define maxN 105

int N;
int arr[maxN];
int result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}

	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=arr[k];
			}
			if(sum%(j-i+1)==0){
				int avg=sum/(j-i+1);
				bool found=false;
				for(int k=i;k<=j;k++){
					if(arr[k]==avg) found=true;
				}
				if(found) result++;
			}
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