#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

int d[20],len,dp[20][2];
//dp[i][0]=# of good numbers up to ith digit st ith digit doesn't end with 2
//dp[i][0]=# of good numbers up to ith digit st ith digit ends with 2
int dfs(int pos,int six,int flag){
  if(pos<0)return 1;
  if(!flag&&dp[pos][six]>-1)return dp[pos][six];
  int up=flag?d[pos]:9,ret=0;
  for(int i=0;i<=up;++i){
    if(i==4)continue;//can not use 4
    if(i==2&&six)continue;//if last one ends with 2 then we can't use 6
    ret+=dfs(pos-1,(i==6),flag&&(i==up));
  }
  if(!flag)dp[pos][six]=ret;
  return ret;
}

int solve(int n){
  len=0;
  while(n){
    d[len++]=n%10;
    n/=10;
  }
  return dfs(len-1,0,1);
}

int main(){
  int l,r;
  memset(dp,-1,sizeof(dp));
  while(~scanf("%d %d",&l,&r)&&(l||r)){
    cout<<solve(r)-solve(l-1)<<endl;
  }
}