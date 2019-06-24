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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//typedef set<int>::iterator ITER;
//#define fi first
//#define se second
//#define INF 0x3f3f3f3f
//#define clr(x,y) memset(x,y,sizeof x)
//const int maxn = 5e6 + 10;
//const int Mod = 1e9 + 7;
//const int N = 2;
/*struct Matrix{Matrix(){clr(m,0);}int m[N][N];};
Matrix Mul(Matrix a,Matrix b){Matrix c;for(int i = 0; i < N; i ++){for(int k = 0; k < N; k ++){if(a.m[i][k] == 0)continue;for(int j = 0; j < N; j ++)c.m[i][j] += a.m[i][k] * b.m[k][j] % Mod,c.m[i][j] %= Mod;}}return c;}
ll Mul(ll a,ll b){a %= Mod;b %= Mod;ll ret = 0;while(b){if(b & 1){ret += a;if(ret > Mod)ret -= Mod;}b >>= 1;a = (a << 1) % Mod;}return ret;}
Matrix pows(Matrix x,ll n){Matrix ret;for(int i = 0; i < 2; i ++)ret.m[i][i] = 1;while(n){if(n & 1)ret = Mul(ret,x);x = Mul(x,x);n >>= 1;}return ret;}
ll pows(ll x,ll n){ll ret = 1;while(n){if(n & 1)ret = ret * x % Mod;x = x * x % Mod;n >>= 1;}return ret;}
ll powss(ll x,ll n){ll ret = 1;while(n){if(n & 1)ret = Mul(ret,x);x = Mul(x,x);n >>= 1;}return ret;}
ll gcd(ll x,ll y){return y ? gcd(y,x % y):x;}
ll lcm(ll x,ll y){return x /gcd(x,y) * y;}

void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){if(!b){d = a;x = 1;y = 0;return;}ex_gcd(b,a % b,d ,y,x);y -=a/b * x;}
inline int lowbit(int x){return x &(-x);}*/
//void update(int x,int val){for(int i = x; x < maxn; i += lowbit(i))tree[i] += val;}
//void get(int x){int ret = 0;for(int i = x; i > 0 ;i -= lowbit(i))ret += tree[i];return ret;}
//int finds(int x){return fa[x] == x ? x : (fa[x] = finds(fa[x]));}
ll euler(int n){
	int ret = n;
	for(int i = 2; i * i<= n; i ++)
		if(n % i == 0){
			ret = ret / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	if(n > 1)
		ret = ret / n * (n - 1);
	return ret;
}
int main()
{	
	int kk;cin>>kk;
	cout<<euler(kk)<<endl;
	return 0;
}