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
int N,xi,yi,MAX,INF=1<<30;
int H[1005],L[1005],R[1005],Rn[1005],Ln[1005],dp[1005][2];
//Rn[i]=在pi往左走往下跳所能到达的合法pj
//Ln[i]=在pi往右走往下跳所能到达的合法pj

static bool cmp(int x,int y){
	return H[x]>H[y];
}


int main(){
	int _;cin>>_;
	while(_--){
		cin>>N>>xi>>yi>>MAX;
		int iii=0;
		vector<int> mp;//indices mapping
		for(;iii<N;iii++){
			cin>>L[iii]>>R[iii]>>H[iii],mp.push_back(iii);
		}
		L[iii]=-20005;R[iii]=20005;H[iii]=0;mp.push_back(iii);//add land
		sort(mp.begin(),mp.end(),cmp);
		int start=-1;
		for(int i=0;i<=N;i++){
			if(xi>L[mp[i]]&&xi<R[mp[i]]&&yi>=H[mp[i]]){//find the first platform
				start=i;
				break;
			}
		}
		for(int i=0;i<N;i++)Rn[i]=Ln[i]=-1;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<=N&&H[mp[i]]-H[mp[j]]<=MAX;j++){
				if(L[mp[j]]<L[mp[i]]&&L[mp[i]]<R[mp[j]]){
					Ln[i]=j;
					break;
				}
			}
			for(int j=i+1;j<=N&&H[mp[i]]-H[mp[j]]<=MAX;j++){
				if(L[mp[j]]<R[mp[i]]&&R[mp[i]]<R[mp[j]]){
					Rn[i]=j;
					break;
				}
			}
			printf("Ln[%d]=%d,Rn[%d]=%d\n",i,Ln[i],i,Rn[i]);
		}
		memset(dp,INF,sizeof(dp));
		dp[N][0]=dp[N][1]=0;
		for(int i=N-1;i>=0;i--){
			if(Ln[i]!=-1){
				int j=Ln[i];
				if(j!=N)dp[i][0]=min(L[mp[i]]-L[mp[j]]+dp[j][0],R[mp[j]]-L[mp[i]]+dp[j][1]);
				else dp[i][0]=0;
			}
			if(Rn[i]!=-1){
				int j=Rn[i];
				if(j!=N)dp[i][1]=min(R[mp[i]]-L[mp[j]]+dp[j][0],R[mp[j]]-R[mp[i]]+dp[j][1]);
				else dp[i][1]=0;
			}
			printf("dp[%d][%d]=%d,dp[%d][%d]=%d\n",i,0,dp[i][0],i,1,dp[i][1]);
		}
		if(start!=N)printf("%d\n",yi+min(xi-L[mp[start]]+dp[start][0],R[mp[start]]-xi+dp[start][1]));
		else cout<<0<<endl;
	}
	return 0;
}