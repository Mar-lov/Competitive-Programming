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

#define INF 200000000
#define maxV 30005

int N,M;
pair<int,int> doge[maxV];
//distance to location 0-N-1 inclusive
int dist[maxV];
bool vdoge[maxV];
priority_queue< pair<int,int> > pq;
//location contains array
vector<int> lc[maxV];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    fill(dist,dist+N,INF);
    for(int i=0;i<M;i++){
        cin>>doge[i].first>>doge[i].second;
        lc[doge[i].first].push_back(i);
    }

    for(int j=0;j<lc[doge[0].first].size();j++){
        pq.push(make_pair(0,lc[doge[0].first][j]));
    }

    dist[doge[0].first]=0;
    while(!pq.empty()&&!vdoge[1]){
        //cd is number of jumps and ci is the current index
        int cd=-1*pq.top().first;
        int ci=pq.top().second;
        pq.pop();
        //if that dog has already been visited there is no need to check again
        if(vdoge[ci]) continue;
        vdoge[ci]=true;
        //loops from current location to 0
        for(int i=0;doge[ci].first-i*doge[ci].second>=0;i++){
            //current location
            int cl=doge[ci].first-i*doge[ci].second;
            if(cd+i<dist[cl]){
                dist[cl]=cd+i;
                for(int j=0;j<lc[cl].size();j++){
                    pq.push(make_pair(-1*dist[cl],lc[cl][j]));
                }
            }
        }
        //to N-1
        for(int i=1;doge[ci].first+i*doge[ci].second<N;i++){ 
            int cl=doge[ci].first+i*doge[ci].second;
            if(cd+i<dist[cl]){
                dist[cl]=cd+i;
                for(int j=0;j<lc[cl].size();j++){
                    pq.push(make_pair(-1*dist[cl],lc[cl][j]));
                }
            }
        }
    }
    if(dist[doge[1].first]==INF){
        cout<<-1<<'\n';
    }else{
        cout<<dist[doge[1].first]<<'\n';
    }
    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/