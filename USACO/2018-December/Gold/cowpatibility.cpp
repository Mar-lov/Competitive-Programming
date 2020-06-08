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

#define maxN 50000

ll N;
ll ans=0;

struct SS{
	int n;
	int vals[5];
};

bool operator< (const SS &a, const SS &b)
{
  for (int j=0; j<5; j++) {
    if (a.vals[j] < b.vals[j]) return true;
    if (a.vals[j] > b.vals[j]) return false;
  }
  return false;
}

SS arr[maxN];
map<SS,int> tp;

int main() {
	ifstream cin("cowpatibility.in");
	ofstream cout("cowpatibility.out");
	cin>>N;
	for(int i=0;i<N;i++){
		arr[i].n=5;
		for(int j=0;j<5;j++){
			cin>>arr[i].vals[j];
		}
		sort(arr[i].vals,arr[i].vals+5);
	}
	for(int i=0;i<N;i++){
		SS cur;
		cur.n=0;
		for(int j=0;j<5;j++){
			cur.vals[j]=0;
		}
		for(int a=0;a<5;a++){
			cur.n=1;
			cur.vals[0]=arr[i].vals[a];
			ans+=tp[cur];
			tp[cur]++;
			for(int b=a+1;b<5;b++){
				cur.n=2;
				cur.vals[1]=arr[i].vals[b];
				ans-=tp[cur];
				tp[cur]++;
				for(int c=b+1;c<5;c++){
					cur.n=3;
					cur.vals[2]=arr[i].vals[c];	
					ans+=tp[cur];
					tp[cur]++;				
					for(int d=c+1;d<5;d++){
						cur.n=4;
						cur.vals[3]=arr[i].vals[d];		
						ans-=tp[cur];
						tp[cur]++;				
						for(int e=d+1;e<5;e++){
							cur.n=5;
							cur.vals[4]=arr[i].vals[e];
							ans+=tp[cur];
							tp[cur]++;
							cur.vals[4]=0;
						}
						cur.vals[3]=0;
					}
					cur.vals[2]=0;
				}
				cur.vals[1]=0;
			}
			cur.vals[0]=0;
		}
	}
	cout<<(N*(N-1)/2)-ans<<'\n';
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/