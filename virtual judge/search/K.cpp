#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <unordered_set>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int maze[5][5],pre[5][5][2];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool v[5][5];

bool in(int i,int j){
	return i>=0&&i<5&&j>=0&&j<5;
}

void printP(int i,int j){
	if(pre[i][j][0]!=i||pre[i][j][1]!=j)
		printP(pre[i][j][0],pre[i][j][1]);
	printf("(%d,%d)\n",i,j);
	return;
}

int main(){
	REP(i,0,5)
		REP(j,0,5)
			cin>>maze[i][j];
	memset(pre,0,sizeof(pre));
	memset(v,false,sizeof(v));
	queue<ii> q;
	q.push({0,0});
	v[0][0]=true;
	pre[0][0][0]=0;
	pre[0][0][1]=0;
	bool found=false;
	while(!q.empty()){
		ii cur=q.front();
		q.pop();
		int x=cur.first,y=cur.second;
		if(x==4&&y==4){
			found=true;
			break;
		}
		REP(i,0,4){
			int xx=x+dx[i],yy=y+dy[i];
			if(in(xx,yy)&&!maze[xx][yy]&&!v[xx][yy]){
				q.push({xx,yy});
				v[xx][yy]=true;
				pre[xx][yy][0]=x;
				pre[xx][yy][1]=y;
			}
		}
	}
	if(found){
		printP(4,4);
	}
	else printf("NO PATH\n");
	return 0;
}