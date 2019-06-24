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
int n,m;//1<=n,m<=10
int a[11];
double A[11],B[11],f[11];
//G(x)=1+x^1/1!+x^2/2!+x^3/3!+...

int main(){
	f[0]=f[1]=1.0;
	REP(i,2,11)f[i]=f[i-1]*i;
	while(~scanf("%d %d",&n,&m)){
		FILL(A,0.0);
		REP(i,0,n)
			scanf("%d",&a[i]);
		REP(j,0,a[0]+1)A[j]=1.0/f[j];
		REP(i,1,n){
			FILL(B,0.0);
			REP(j,0,m+1){
				for(int k=0;k<=a[i]&&k+j<=m;k++){
					B[j+k]+=A[j]*1.0/f[k];
				}
			}
			REP(j,0,11)A[j]=B[j];
		}
		printf("%.0f\n",A[m]*f[m]);
	}
	return 0;
}