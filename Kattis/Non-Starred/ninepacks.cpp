#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXW = 1e5 + 5;
void print(int x) {
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void read(int &x) {
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main() {
    int dp[2][MAXW]; memset(dp, INF, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    int n, sum_n = 0; read(n); vector<int> data_n(n);
    for (auto &v : data_n) cin >> v, sum_n += v;
    for (auto &v : data_n) {
        for (int j = sum_n ; j >= v ; j--)
            dp[0][j] = min(dp[0][j], dp[0][j - v] + 1);
    }
    int m, sum_m = 0; read(m); vector<int> data_m(m);
    for (auto &v : data_m) cin >> v, sum_m += v;
    for (auto &v : data_m) {
        for (int j = sum_m ; j >= v ; j--)
            dp[1][j] = min(dp[1][j], dp[1][j - v] + 1);
    }
    int ans = INF, top = min(sum_n, sum_m);
    for (int i = 1 ; i <= top ; i++)
        ans = min(ans, dp[0][i] + dp[1][i]);
    if (ans == INF) puts("impossible");
    else print(ans), puts("");
}
