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
#include <unordered_map>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

struct person{
	int d,p;
}a[205];

int m,n,diff,sum,P,D;
vector<int> ret;
//1<=m<=20,1<=n<=200
//0<=di<=20,0<=pi<=20
//minimize |P(J)-D(J)| then maximize |P(J)+D(J)|
void solve(vector<int>& vi,int Pj,int Dj,int num,int pos){ //O(2^n)
	if(pos==n)return;
	if(!num){
		if(abs(Dj-Pj)<diff)diff=abs(Dj-Pj),ret=vi,sum=Dj+Pj,D=Dj,P=Pj;
		else if(abs(Dj-Pj)==diff&&Dj+Pj>sum)sum=Dj+Pj,ret=vi,D=Dj,P=Pj;
	}
	else{
		vi.push_back(pos);
		solve(vi,Pj+a[pos].p,Dj+a[pos].d,num-1,pos+1);
		vi.pop_back();
		solve(vi,Pj,Dj,num,pos+1);
	}
}

int main(){
	int r=1;
	while(~scanf("%d %d",&n,&m)&&n&&m){
		REP(i,0,n)scanf("%d %d",&a[i].p,&a[i].d);
		diff=1<<30;sum=-1;
		vector<int> vi;
		solve(vi,0,0,m,0);
		sort(vi.begin(),vi.end());
		printf("Jury #%d\n",r);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",P,D);
		REP(i,0,m)printf("%d ",ret[i]+1);//升序
		printf("\n");
		++r;
	}
	return 0;
}