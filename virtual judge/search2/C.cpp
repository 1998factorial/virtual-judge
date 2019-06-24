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

vector<int> g[21];
vector<int> path;
bool v[25];
int n,cur;

void solve(int i,int j){
	if(j==20){
		if(i==cur){//path found
			printf("%d:  %d",n++,cur);
			REP(k,0,20)printf(" %d",path[k]);
			printf("\n");
		}
		else {return;}//not cycle
	}
	else if(j!=0&&i==cur){return;}
	else{
		REP(k,0,3){
			if(!v[g[i][k]]){
				v[g[i][k]]=true;
				path.push_back(g[i][k]);
				solve(g[i][k],j+1);
				path.pop_back();
				v[g[i][k]]=false;
			}
		}
	}
}

int main(){
	REP(i,0,21)g[i].clear();
	REP(i,1,21){
		int x,y,z;
		cin>>x>>y>>z;
		g[i].push_back(x);
		g[i].push_back(y);
		g[i].push_back(z);
		sort(g[i].begin(),g[i].end());
	}
	while(~scanf("%d",&cur)&&cur){
		path.clear();
		memset(v,false,sizeof(v));
		n=1;
		solve(cur,0);
	}
	return 0;
}