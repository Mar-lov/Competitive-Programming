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

#define maxV 200005
#define maxC 105

int totalX[maxV];
int total_[maxV];

//0 if not possible 1 if only add X's 2 is only add _ and 3 is both 1 and 2
short dp[maxC][maxV];


int poss_[maxV];
int deltaX[maxV];
vector<int> c;
bool visited[maxC][maxV];

void findV(int i,int j){
	if(i<0||j<0) return;
	if(visited[i][j]) return;
	int cv=dp[i][j];
	//cout<<i<<","<<j<<" has "<<cv<<'\n';
	visited[i][j]=true;
	if(cv==1){
		deltaX[j-c[i-1]+1]++;
		deltaX[j+1]--;
		poss_[j-c[i-1]]++;
		findV(i-1,j-c[i-1]-1);
	}else if(cv==2){
		poss_[j]++;
		findV(i,j-1);
	}else if(cv==3){
		deltaX[j-c[i-1]+1]++;
		deltaX[j+1]--;
		poss_[j-c[i-1]]++;
		poss_[j]++;
		findV(i,j-1);
		findV(i-1,j-c[i-1]-1);
	}
}

//1 base index location within the string
string solve_puzzle(string s,vector<int> carr){
	c=carr;
	string result="";
	s="."+s;
	for(int i=1;i<s.length();i++){
		totalX[i]=totalX[i-1]+(s[i]=='X'?1:0);
		total_[i]=total_[i-1]+(s[i]=='_'?1:0);
	}
	int ci=0;
	while(s[ci]!='X'&&ci<s.length()){
		dp[0][ci]=2;
		ci++;
	}
	for(int i=0;i<c.size();i++){
		for(int j=1;j<s.length();j++){
			//(dp[i][j-c[i]-2]>0)&&s[j-c[i]-1]!='X' to place _
			bool addX=false;
			if(j>=c[i]) addX=(dp[i][j-c[i]]>1)&&(total_[j]-total_[j-c[i]]==0);
			//possible if also dp[i+1][j-1] works?
			bool add_=(dp[i+1][j-1]>0&&s[j]!='X');
			if(addX&&!add_){
				dp[i+1][j]=1;
			}else if(!addX&&add_){
				dp[i+1][j]=2;
			}else if(addX&&add_){
				dp[i+1][j]=3;
			}
			//cout<<dp[i+1][j]<<" ";
		}
		//cout<<'\n';
	}
	//cout<<'\n';
	findV(c.size(),s.length()-1);
	int csum=0;
	for(int i=0;i<s.length();i++){
		csum+=deltaX[i];
		deltaX[i]=csum;
	}
	/*
	for(int i=1;i<s.length();i++){
		cout<<deltaX[i]<<" and "<<poss_[i]<<'\n';
	}
*/
	for(int i=1;i<s.length();i++){
		bool canX=deltaX[i]>0;
		bool can_=poss_[i]>0;
		if(canX&&can_){
			result+='?';
		}else if(canX&&!can_){
			result+='X';
		}else if(!canX&&can_){
			result+='_';
		}
	}
	//cout<<result.length()<<'\n';
	return result;
}
/*
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solve_puzzle("……….", {5,4} )<<'\n';

    return 0;
}
*/
/*stuff you should look for
	* int overflow, array bounds
	* special cases (n=1,n=0?)
	* do smth instead of nothing and stay organized
*/