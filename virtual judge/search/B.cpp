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

int L,R,C;
char a[35][35][35];
bool v[35][35][35];
int xi,yi,zi,xf,yf,zf;
int dz[6]={1,-1,0,0,0,0},dx[6]={0,0,1,-1,0,0},dy[6]={0,0,0,0,1,-1};
struct state{
	int z,x,y,d;
};

bool inside(int i,int j,int k){
	return i>=0&&i<L&&j>=0&&j<R&&k>=0&&k<C;
}

int main(){
	while(~scanf("%d %d %d",&L,&R,&C)&&(L||R||C)){
		REP(i,0,L){
			REP(j,0,R){
				REP(k,0,C){
					cin>>a[i][j][k];
					if(a[i][j][k]=='S'){
						zi=i;xi=j;yi=k;
					}
					if(a[i][j][k]=='E'){
						zf=i;xf=j;yf=k;
					}	
				}
			}
		}
		memset(v,false,sizeof(v));
		queue<state> q;
		q.push({zi,xi,yi,0});
		v[zi][xi][yi]=true;
		bool found=false;
		while(!q.empty()&&!found){
			while(!q.empty()&&!found){
				state cur=q.front();
				q.pop();
				int xx=cur.x,zz=cur.z,yy=cur.y,dd=cur.d;
				if(zz==zf&&xx==xf&&yy==yf){
					printf("Escaped in %d minute(s).",dd);
					found=true;
				}
				else{
					for(int i=0;i<6;i++){
						int aa=zz+dz[i],bb=xx+dx[i],cc=yy+dy[i];
						if(inside(aa,bb,cc)&&a[aa][bb][cc]!='#'&&!v[aa][bb][cc]){
							q.push({aa,bb,cc,dd+1});v[aa][bb][cc]=true;
						}
					}
				}
			}
		}	
		if(!found)printf("Trapped!\n");
	}
	return 0;
}