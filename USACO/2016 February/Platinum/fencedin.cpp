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
typedef pair<long long,long long> pi;



long long A,B,n,m;
vector<long long> col;
vector<long long> row;
vector<pi> val;
long long tc=0;
long long tr=0;
long long result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream cin("fencedin.in");
	ofstream cout("fencedin.out");
	cin>>A>>B>>n>>m;
	col.push_back(0);
	row.push_back(0);
	long long temp;
	for(long long i=0;i<n;i++){
		cin>>temp;
		col.push_back(temp);
	}
	for(long long i=0;i<m;i++){
		cin>>temp;
		row.push_back(temp);
	}
	col.push_back(A);
	row.push_back(B);
	sort(col.begin(),col.end());
	sort(row.begin(),row.end());
	for(long long i=1;i<col.size();i++){
		val.push_back(make_pair(col[i]-col[i-1],0));
		//cout<<val.back().first<<" ";
	}
	//cout<<'\n';
	for(long long i=1;i<row.size();i++){
		val.push_back(make_pair(row[i]-row[i-1],1));
		//cout<<val.back().first<<" ";
	}
	//cout<<"\n";
	sort(val.begin(),val.end());
	for(long long i=0;i<val.size();i++){
		pi cur=val[i];
		long long cc=cur.first;
		long long type=cur.second;
		
		if(type==0){
			if(tr>1&&tc>0){
				result+=(m+1-tr)*cc;
			}else{
				result+=(m)*cc;
			}
			tc++;
		}else if(type==1){
			if(tc>1&&tr>0){
				result+=(n+1-tc)*cc;
				//cout<<"VAL:"<<(n+1-tc)*cc<<'\n';
			}else{
				result+=(n)*cc;
			}
			tr++;
		}
		//cout<<result<<'\n';
		//if(m-tr<0||n-tc<0) cout<<"ERROR"<<m-tr<<" "<<n-tc<<endl;
	}
	cout<<result<<'\n';
    return 0;
}

/* stuff you should look for
	* long long overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/