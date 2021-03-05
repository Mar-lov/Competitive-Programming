#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int loc[210][210];

int xd[4]={0,-1,0,1};
int yd[4]={-1,0,1,0};

void flood(int x,int y){
  loc[x][y]=2;
  for(int i=0;i<4;i++){
    int nx=x+xd[i];
    int ny=y+yd[i];
    if(nx<0||nx>=210||ny<0||ny>=210) continue;
    if(loc[nx][ny]==1||loc[nx][ny]==2) continue;
    flood(nx,ny);
  }
}

int dx(char c){
  if(c=='W') return -1;
  if(c=='E') return 1;
  return 0;
}
int dy(char c){
  if(c=='N') return 1;
  if(c=='S') return -1;
  return 0;
}

//character value perpendicular to current value
char per(char c){
  if(c=='N') return 'E';
  if(c=='S') return 'W';
  if(c=='W') return 'N';
  if(c=='E') return 'S';
  return 0;
}

int main() {
  int N;
  cin>>N;
  cin.ignore();
  string s;
  for(int i=0;i<N;i++){
    getline(cin,s);
    for(int a=0;a<210;a++){
      for(int b=0;b<210;b++){
        loc[a][b]=0;
      }
    }
    //sets orgin of graph as 105
    int cx=105;
    int cy=105;
    loc[cx][cy]=1;
    for(int j=0;j<s.length();j++){
      cx+=dx(s[j]);
      cy+=dy(s[j]);
      loc[cx][cy]=1;
    }
    //floods the graph
    flood(0,0);
    //reset location
    cx=105;
    cy=105;
    bool CW=true;
    //runs through the graph chcking the value to the right
    for(int j=0;j<s.length();j++){
      cx+=dx(s[j]);
      cy+=dy(s[j]);
      char pv=per(s[j]);
      if(loc[cx+dx(pv)][cy+dy(pv)]==2){ 
        CW=false;
      }
    }

    if(CW){
      cout<<"CW"<<endl;
    }else{
      cout<<"CCW"<<endl;
    }
  }
  return 0;
}