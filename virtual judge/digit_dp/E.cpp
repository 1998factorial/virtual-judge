#include <iostream>
#include <cstring>
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<b;++i)

using namespace std;
typedef long long ll;
ll l,r,dp[36][64];
int d[36],len;

ll DFS(int pos,int diff,int flag,int lead){
  if(pos<1)return diff>=32;
  if(!flag&&lead&&dp[pos][diff]>-1)return dp[pos][diff];
  int up=flag?d[pos]:1;
  ll ret=0;
  for(int i=0;i<=up;++i){
    if(lead){ //has leading one
      ret+=DFS(pos-1,(i==0)?diff+1:diff-1,flag&&(i==up),lead||i);
    }
    else{ //if no leading one
      if(i)ret+=DFS(pos-1,diff-1,flag&&(i==up),lead||i); //we now have a leading
      else ret+=DFS(pos-1,diff,flag&&(i==up),lead||i); //we skip this one
    }
  }
  if(!flag&&lead)dp[pos][diff]=ret;
  return ret;
}

ll solve(ll n){
  len=1;
  for(;n;n>>=1)d[len++]=n&1;
  return DFS(len-1,32,1,0);
}

int main(){
  memset(dp,-1,sizeof(dp));
  while(cin>>l>>r){
    cout<<solve(r)-solve(l-1)<<endl;
  }
  /*REP(i,0,36)
    REP(j,0,64)
      printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);*/
}