// Problem Link: https://leetcode.com/problems/rotate-image/

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

void rotate(vector<vector<int>> &ar)
{
    int n = ar.size(), m = ar[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(ar[i][j], ar[j][i]);
        }
    }

    for (int r = 0; r < n; r++)
    {
        reverse(ar[r].begin(), ar[r].end());
    }
}

void testcase()
{
    int n, i, j;
    cin >> n;
    vii ar(n, vi(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> ar[i][j];
        }
    }
    rotate(ar);
    rep(i, n)
    {
        rep(j, n)
        {
            cout << ar[i][j] << " ";
        }
        cout << "\n";
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
