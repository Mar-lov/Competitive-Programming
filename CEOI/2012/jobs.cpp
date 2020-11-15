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
typedef pair<long long,long long> pi;
 
 
#define maxN 100005
 
long long N,D,M;
vector<long long> arr[maxN];
vector<long long> ans;
bool solve(long long num){
    priority_queue< pair<long long,long long> , vector< pair<long long,long long> > , greater< pair<long long,long long> > > pq;
    for(long long i=0;i<N;i++){
        long long cc=num;
        if(arr[i].size()>0) pq.push(make_pair(i,arr[i].size()));
        while(!pq.empty()&&cc>0){
            if(pq.top().first<i-D) return false;
            if(pq.top().second<=cc){
                cc-=pq.top().second;
                pq.pop();
            }else if(pq.top().second>cc){
                pair<long long,long long> cur=pq.top();pq.pop();
                cur.second-=cc;
                pq.push(cur);
                cc=0;
            }
        }
    }
    if(pq.size()>0) return false;
    return true;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>D>>M;
    long long num;
    for(long long i=0;i<M;i++){
        cin>>num;
        num--;
        arr[num].push_back(i);
    }
    long long a=0;
    long long b=1000000;
    while(a<b){
        long long mid=(a+b)/2;
        if(solve(mid)){
            b=mid;
        }else{
            a=mid+1;
        }
        //cout<<a<<" "<<mid<<" "<<b<<endl;
    }
    for(long long i=0;i<N;i++){
        for(long long j=0;j<arr[i].size();j++){
            ans.push_back(arr[i][j]);
        }
    }
    cout<<a<<'\n';
    long long ci=0;
    for(long long i=0;i<N;i++){
        for(long long j=0;j<a;j++){
            if(ci==ans.size()) break;
            cout<<ans[ci]+1<<" ";
            ci++;
        }
        cout<<0<<endl;
    }
    return 0;
}
 
/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/