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

#define maxN 200005

long long T;
long long N;
long long arr[maxN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
    while(T--){
        cin>>N;
        N+=2;
        for(long long i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr,arr+N);
        long long csum=0;
        multiset<long long> vals;
        for(long long i=0;i<N-2;i++){
            csum+=arr[i];
            vals.insert(arr[i]);
        }
        bool works=true;
        if(!(csum==arr[N-1]||csum==arr[N-2])){
            csum+=arr[N-2];
            if(vals.count(csum-arr[N-1])>0){
                vals.erase(vals.find(csum-arr[N-1]));
                vals.insert(arr[N-2]);
            }else{
                csum-=arr[N-2];
                csum+=arr[N-1];
                if(vals.count(csum-arr[N-2])){
                    vals.erase(vals.find(csum-arr[N-2]));
                    vals.insert(arr[N-1]);
                }else{
                    works=false;
                }
            }
        }
        if(!works){
            cout<<-1;
        }else{
        for(long long a:vals){
            cout<<a<<" ";
        }
        }
        cout<<endl;
    }
    return 0;
}

/* IF STUCK LOOK HERE
	* long long overflow, use long long
	* array bounds
	* edge cases (n=0,n=1)
	* values not distinct?
	* do smth instead of nothing and stay organized
*/