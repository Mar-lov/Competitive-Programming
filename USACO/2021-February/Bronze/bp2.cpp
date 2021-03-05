#include <iostream>
#include <vector>
using namespace std;

#define maxB 1001

int N;
bool graph[maxB][maxB];
bool isComfy[maxB][maxB];
int totalComfy=0;

void adjVals(int x,int y){
  if(graph[x][y]==false) return;
  int ans=0;
  if(graph[x-1][y]) ans++;
  if(graph[x+1][y]) ans++;
  if(graph[x][y-1]) ans++;
  if(graph[x][y+1]) ans++;
  if(ans==3&&!isComfy[x][y]){
    isComfy[x][y]=true;
    totalComfy++;
  }else if(isComfy[x][y]&&ans!=3){
    isComfy[x][y]=false;
    totalComfy--;
  }
}

void newVal(int x,int y){
  adjVals(x,y);
  adjVals(x-1,y);
  adjVals(x+1,y);
  adjVals(x,y-1);
  adjVals(x,y+1);
}

int main() {
  cin>>N;
  for(int i=0;i<maxB;i++){
    for(int j=0;j<maxB;j++){
      graph[i][j]=false;
      isComfy[i][j]=false;
    }
  }
  vector<int> x;
  vector<int> y;
  int ix,iy;
  for(int i=0;i<N;i++){
    cin>>ix>>iy;
    x.push_back(ix);
    y.push_back(iy);
  }

  for(int i=0;i<N;i++){
    graph[x[i]][y[i]]=true;
    newVal(x[i],y[i]);
    cout<<totalComfy<<'\n';
  }

  return 0;
}