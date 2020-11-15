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

#define maxN 500005

int N;
int input[maxN];
long long cmb[maxN];

struct Node{
	int val;
	int num;
	int left;
	int right;
};

Node arr[maxN];
vector<pi> order;
long long result=0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	fill(input,input+maxN,-1);
	cmb[1]=0;
	cmb[2]=1;
	for(int i=3;i<maxN;i++){
		cmb[i]=cmb[i-1]+i-1;
	}
	for(int i=1;i<=N;i++){
		cin>>input[i];
	}
	int cn=0;
	for(int i=1;i<=N;i++){
		if(input[i]==input[i-1]){
			arr[cn].num++;
		}else{
			cn++;
			arr[cn].val=input[i];
			arr[cn].num=1;
			arr[cn].left=cn-1;
			arr[cn].right=cn+1;
			order.push_back(make_pair(arr[cn].val,cn));
		}
	}
	arr[1].left=-1;
	arr[cn].right=-1;
	sort(order.begin(),order.end());
	//what if creation of one large group
	for(int i=0;i<order.size();i++){
		int cl=order[i].second;
		int nb=0;
		if(arr[cl].left!=-1){
			arr[arr[cl].left].right=arr[cl].right;
			nb++;
		}
		if(arr[cl].right!=-1){
			arr[arr[cl].right].left=arr[cl].left;
			nb++;
		}
		if(arr[cl].left!=-1&&arr[arr[cl].left].val==arr[cl].val){
			arr[arr[cl].left].num+=arr[cl].num;
			continue;
		}
		if(arr[cl].right!=-1&&arr[arr[cl].right].val==arr[cl].val){
			arr[arr[cl].right].num+=arr[cl].num;
			continue;
		}
		//cout<<cl<<'\n';
		result+=arr[cl].num*nb;
		result+=cmb[arr[cl].num];
	}
	cout<<result<<'\n';

    return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/