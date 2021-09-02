// Problem Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

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
#define input(n) cin >> (n)
#define print(n) cout << (n)

vector<int> xorQueries(vector<int> &ar, vector<vector<int>> &q)
{
    int n = ar.size();
    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        t[i] = (t[i - 1] ^ ar[i - 1]);
    }
    vector<int> ans;
    for (int i = 0; i < q.size(); i++)
    {
        int l = q[i][0], r = q[i][1] + 1;
        ans.push_back((t[r] ^ t[l]));
    }
    return ans;
}

void testcase()
{
    int i, n, q;
    cin >> n >> q;
    vi ar(n);
    vii queries(q, vi(2));
    rep(i, n)
    {
        cin >> ar[i];
    }
    rep(i, q)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    vi x = xorQueries(ar, queries);
    rep(i, x.size())
    {
        cout << x[i] << " ";
    }
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
