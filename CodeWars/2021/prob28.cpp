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

#define maxB 400

int s;
int e;
map<int,string> toS;
char graph[maxB][maxB];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
toS[1]="one";
toS[2]="two";
toS[3]="three";
toS[4]="four";
toS[5]="five";
toS[6]="six";
toS[7]="seven";
toS[8]="eight";
toS[9]="nine";
toS[10]="ten";
toS[11]="eleven";
toS[12]="twelve";
toS[13]="thirteen";
toS[14]="fourteen";
toS[15]="fifteen";
toS[16]="sixteen";
toS[17]="seventeen";
toS[18]="eighteen";
toS[19]="nineteen";
toS[20]="twenty";
toS[21]="twentyone";
toS[22]="twentytwo";
toS[23]="twentythree";
toS[24]="twentyfour";
toS[25]="twentyfive";
toS[26]="twentysix";
toS[27]="twentyseven";
toS[28]="twentyeight";
toS[29]="twentynine";
toS[30]="thirty";
toS[31]="thirtyone";
toS[32]="thirtytwo";
toS[33]="thirtythree";
toS[34]="thirtyfour";
toS[35]="thirtyfive";
toS[36]="thirtysix";
toS[37]="thirtyseven";
toS[38]="thirtyeight";
toS[39]="thirtynine";
toS[40]="forty";
toS[41]="fortyone";
toS[42]="fortytwo";
toS[43]="fortythree";
toS[44]="fortyfour";
toS[45]="fortyfive";
toS[46]="fortysix";
toS[47]="fortyseven";
toS[48]="fortyeight";
toS[49]="fortynine";
toS[50]="fifty";
toS[51]="fiftyone";
toS[52]="fiftytwo";
toS[53]="fiftythree";
toS[54]="fiftyfour";
toS[55]="fiftyfive";
toS[56]="fiftysix";
toS[57]="fiftyseven";
toS[58]="fiftyeight";
toS[59]="fiftynine";
toS[60]="sixty";
toS[61]="sixtyone";
toS[62]="sixtytwo";
toS[63]="sixtythree";
toS[64]="sixtyfour";
toS[65]="sixtyfive";
toS[66]="sixtysix";
toS[67]="sixtyseven";
toS[68]="sixtyeight";
toS[69]="sixtynine";
toS[70]="seventy";
toS[71]="seventyone";
toS[72]="seventytwo";
toS[73]="seventythree";
toS[74]="seventyfour";
toS[75]="seventyfive";
toS[76]="seventysix";
toS[77]="seventyseven";
toS[78]="seventyeight";
toS[79]="seventynine";
toS[80]="eighty";
toS[81]="eightyone";
toS[82]="eightytwo";
toS[83]="eightythree";
toS[84]="eightyfour";
toS[85]="eightyfive";
toS[86]="eightysix";
toS[87]="eightyseven";
toS[88]="eightyeight";
toS[89]="eightynine";
toS[90]="ninety";
toS[91]="ninetyone";
toS[92]="ninetytwo";
toS[93]="ninetythree";
toS[94]="ninetyfour";
toS[95]="ninetyfive";
toS[96]="ninetysix";
toS[97]="ninetyseven";
toS[98]="ninetyeight";
toS[99]="ninetynine";
toS[100]="onehundred";

	cin>>s>>e;
	for(int i=0;i<maxB;i++){
		for(int j=0;j<maxB;j++){
			graph[i][j]='.';
		}
	}
	int si=200;
	int sj=200;
	for(int i=s;i<=e;i++){
		solve(si,sj,i);
		si-1;
		
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