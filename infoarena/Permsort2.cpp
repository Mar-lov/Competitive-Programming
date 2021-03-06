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
typedef pair<int,int> ii;

#define maxN 100005

int N;
int arr[maxN];
int AS;
vector<int> ans;

int ft[100013];
void update(int x, int v) {while(x<=N) ft[x]+=v, x+=(x&-x);}
int query (int x) {return (x>0 ? ft[x]+query(x-(x&-x)):0);}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("permsort2.in");
	ofstream cout("permsort2.out");
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	AS=N-1;
	update(arr[N-1],1);
	for(int i=N-2;i>=0;i--){
		if(arr[i+1]>arr[i]){
			AS=i;
			update(arr[i],1);
		}else{
			break;
		}
	}
	int sv=AS;
	for(int i=0;i<sv;i++){
		int ssv=query(arr[i]);
		//cout<<arr[i]<<" "<<ssv<<'\n';
		ans.push_back(AS+ssv);
		ans.push_back(AS+ssv-1);
		AS--;
		update(arr[i],1);
	}

	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<"P "<<ans[i]<<'\n';
	}
	
	
    return 0;
}

/* IF STUCK LOOK HERE
	* int overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/