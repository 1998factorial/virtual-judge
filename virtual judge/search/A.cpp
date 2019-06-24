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
//#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
int n,k;
ll ret;
char a[9][9];
bool col[9];
void solve(int i,int nn){
	if(nn<=0){
		ret++;
		return;
	}
	if(i>=n)return;
	REP(j,0,n){
		if(col[j]==false&&a[i][j]=='#'){
			col[j]=true;
			solve(i+1,nn-1);
			col[j]=false;
		}
	}
	solve(i+1,nn);//give up this row
}

int main(){
	while(~scanf("%d %d",&n,&k)&&!(n==-1&&k==-1)){
		REP(i,0,n)
			REP(j,0,n)
				cin>>a[i][j];
		ret=0ll;
		memset(col,false,sizeof(col));
		solve(0,k);
		printf("%lld\n",ret);
	}
	return 0;
}