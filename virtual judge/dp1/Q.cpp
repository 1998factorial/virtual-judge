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
int n;
string a[1005];
int dp[1005][1005];
int main(){
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ret=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==0||j==n-1)dp[i][j]=1;
				else{
					//go up&right,stop when differ
					int ii=i,jj=j;
					while(ii>=0&&jj<n&&a[ii][j]==a[i][jj]){
						--ii;
						++jj;
					}
					ii=i-ii;//candidate size
					if(ii>dp[i-1][j+1]+1)dp[i][j]=dp[i-1][j+1]+1;
					else dp[i][j]=ii;
					ret=max(ret,dp[i][j]);
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}