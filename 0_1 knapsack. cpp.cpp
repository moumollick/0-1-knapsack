
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define trace(x) cout << #x << ": " << x << endl
const int N = 1e5 + 100;
int price[N], weight[N], n, mx_w;
ll dp[1000][N];
ll solve(int i, int current_w)
{
    if(i > n) return 0;
    if(dp[i][current_w] != -1) return dp[i][current_w];
    ll nibo = 0, nibona = 0;
    if(current_w + weight[i] <= mx_w)
    {
        nibo = price[i] + solve(i + 1, current_w + weight[i]);
    }
    nibona = solve(i + 1, current_w);
    return dp[i][current_w] = max(nibo, nibona);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mx_w;
    for(int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> price[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0) << endl;
    return 0;
}