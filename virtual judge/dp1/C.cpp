#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//sort + longest increasing dp
typedef long long int64;
int x[31],y[31],z[31];
int n;
vector<vector<int> > A;
int64 dp[93];
//dp[i] the maximal height of tower we can get by using A[i][0] and A[i][1] as base

static bool cmp(vector<int> a, vector<int> b){ //sort by area
    return a[0]*a[1] < b[0]*b[1];
}

int64 solve(){
    A.clear();
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < n; i++){
        vector<int> a1(3),a2(3),a3(3);
        //(x,y) (y,z) (x,z)
        a1[0] = x[i],a2[0] = y[i],a3[0] = z[i];
        a1[1] = z[i],a2[1] = x[i],a3[1] = y[i];
        a1[2] = y[i],a2[2] = z[i],a3[2] = x[i];
        A.push_back(a1),A.push_back(a2),A.push_back(a3);
    }
    sort(A.begin(),A.end(),cmp);//sort by area
    int64 ret = 0;
    for(int i = 0; i < 3*n; i++){
        dp[i] = A[i][2];
        for(int j = 0; j < i; j++){
            if((A[i][0] > A[j][0] && A[i][1] > A[j][1]) || (A[i][0] > A[j][1] && A[i][1] > A[j][0])){ //can extend
                dp[i] = max(dp[i],dp[j]+A[i][2]);
            }
        }
        ret = max(ret,dp[i]);
    }
    return ret;
}


int main(){
    int c = 1;
    while(scanf("%d",&n) != EOF && n != 0){
        for(int i = 0; i < n; i++){
            cin >> x[i], cin >> y[i], cin >> z[i];
        }
        int64 ans = solve();
        cout << "Case " << c << ": maximum height = " << ans << endl;
        c++;
    }
    return 0;
}