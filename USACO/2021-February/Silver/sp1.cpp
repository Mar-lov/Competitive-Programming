#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int B=4100;

int N;
pair<int,int> arr[100005];
int graph[B][B];
int total=0;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void check(int x,int y);
void add(int x,int y,int t);

void check(int x,int y){
  int surround=0;
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(graph[nx][ny]!=-1) surround++;
  }

  if(surround==3){
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(graph[nx][ny]==-1){
        add(nx,ny,1);
        check(nx,ny);
        break;
      }
    }
  }

}

void add(int x,int y,int t){
  if(graph[x][y]==1) total--;
  if(t==1) total++;
  graph[x][y]=t;
  check(x,y);
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(graph[nx][ny]!=-1) check(nx,ny);
  }
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>arr[i].first>>arr[i].second;
    arr[i].first+=(B/2)-500;
    arr[i].second+=(B/2)-500;
  }

  for(int i=0;i<B;i++){
    for(int j=0;j<B;j++){
      graph[i][j]=-1;
    }
  }

  for(int i=0;i<N;i++){
    add(arr[i].first,arr[i].second,0);
    cout<<total<<'\n';
  }

  return 0;
}