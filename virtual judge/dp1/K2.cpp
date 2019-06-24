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
//1<=m<=20,1<=n<=200
//0<=di<=20,0<=pi<=20
//minimize |P(J)-D(J)| then maximize |P(J)+D(J)|
int m,n,dp[25][810],path[25][810],P[205],D[205],og;
//dp[i][j]=when selected i ppl,and the abs diff is j,the maximal sum of P and D

bool check(int i,int j,int k){//check if k is in the path of (i,j)
	while(i&&path[i][j]!=k){
		j-=P[path[i][j]]-D[path[i][j]];
		i--;
	}
	return (i==0);
}

int main(){
	int r=1;
	while(~scanf("%d %d",&n,&m)&&n&&m){
		og=m*20;
		REP(i,1,n+1)
			scanf("%d %d",&P[i],&D[i]);
		FILL(dp,-1);FILL(path,0);
		dp[0][og]=0;
		//when choosing no one,and diff=0,maximal sum is 0
		REP(i,1,m+1){
			REP(j,0,2*og+1){
				if(dp[i-1][j]>-1){
					REP(k,1,n+1){
						if(dp[i][j+P[k]-D[k]]<dp[i-1][j]+P[k]+D[k]&&check(i-1,j,k)){
							dp[i][j+P[k]-D[k]]=dp[i-1][j]+P[k]+D[k];
							path[i][j+P[k]-D[k]]=k;
						}
					}
				}
			}
		}
		int opt=0,i=0;
		while(dp[m][og+i]<0&&dp[m][og-i]<0)i++;
		opt=(dp[m][og+i]>dp[m][og-i])?og+i:og-i;
		printf("Jury #%d\n",r++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[m][opt]+opt-og)/2,(dp[m][opt]-opt+og)/2);
		vector<int> a;
		while(m){
			a.push_back(path[m][opt]);
			opt-=P[path[m][opt]]-D[path[m][opt]];
			m--;
		}
		sort(a.begin(),a.end());
		for(i=0;i<a.size();i++)printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
