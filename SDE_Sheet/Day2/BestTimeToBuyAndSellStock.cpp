// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, k, n) for (i = k; i >= n; i--)
#define pii pair<int, int>
#define PB push_back

int maxProfit(vector<int> &prices)
{
    int mn = prices[0], mx = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        mn = min(mn, prices[i]);
        mx = max(mx, prices[i] - mn);
    }
    return mx;
}

void testcase()
{
    int n, i;
    cin >> n;
    vi ar(n);
    rep(i, n)
    {
        cin >> ar[i];
    }
    cout << maxProfit(ar);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto start = high_resolution_clock::now();
    // ll t;
    // cin >> t;
    // while(t--)
    testcase();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    return 0;
}
