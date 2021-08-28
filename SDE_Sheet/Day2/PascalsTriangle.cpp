// Problem Link: https://leetcode.com/problems/pascals-triangle/

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

vector<vector<int>> generate(int n)
{
    vector<vector<int>> ans;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        c = 1;
        vector<int> t;
        t.push_back(c);
        for (int j = 0; j < i; j++)
        {
            // nCr+1 = (nCr * (n - r)) / (r + 1)
            c = (((i - j) * c) / (j + 1));
            t.push_back(c);
        }
        ans.push_back(t);
    }
    return ans;
}

void testcase()
{
    int n, i, j;
    cin >> n;
    vii ar;
    ar = generate(n);
    rep(i, ar.size())
    {
        rep(j, ar[j].size())
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
