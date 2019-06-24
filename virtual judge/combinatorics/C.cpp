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

//trains must leave in strict-increasing order 
//if in=( out=), then at any point,number of ) must not exceeds number of ) 
//thus, the problem is asking the nth catalan-number
//N最大100，所以会爆，要用高精度乘法
//C[i]=(2nCn)/(n+1)
//C[i]=(4*i-2)*C[i-1]/(n+1)
int a[105][105],n; //use array to store catalan numbers

void solve(){
	int r=0,len=1;
	a[1][0]=a[1][1]=1;
	for(int i=2;i<105;i++){
		for(int j=1;j<=len;j++){
			int t=a[i-1][j]*(4*i-2)+r;
			r=t/10;
			a[i][j]=t%10;
		}
		while(r){
			a[i][++len]=r%10;
			r/=10;
		}
		for(int j=len;j>0;j--){
			int t=a[i][j]+r*10;
			a[i][j]=t/(i+1);
			r=t%(i+1);
		}
		while(!a[i][len])len--;
		a[i][0]=len;
	}
}

int main(){
	solve();
	while(~scanf("%d",&n)){
		for(int i=a[n][0];i>0;i--)printf("%d",a[n][i]);
		cout<<endl;
	}
	return 0;
}