// Problem Link: https://leetcode.com/problems/set-matrix-zeroes/

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

// Time O(n ^ 2)
// space O(n)
void setZeroes1(vector<vector<int>> &matrix)
{
    int r = matrix.size(), c = matrix[0].size();
    vector<int> row(r, 0), col(c, 0); // row and column vectors to mark true when row is 0 or column is zero
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    // make all marked rows 0
    for (int i = 0; i < r; i++)
    {
        if (row[i] > 0)
        {
            for (int j = 0; j < c; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // make all marked columns 0
    for (int i = 0; i < c; i++)
    {
        if (col[i] > 0)
        {
            for (int j = 0; j < r; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}

// Space optimal solution
// Time O(n ^ 2)
// space O(1)
void setZeroes2(vector<vector<int>> &matrix)
{
    int col0 = 1, r = matrix.size(), c = matrix[0].size();

    for (int i = 0; i < r; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < c; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}

void testcase()
{
    int n, m;
    cin >> n >> m;
    vii mat(n, vi(m));
    int i, j;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> mat[i][j];
        }
    }
    setZeroes1(mat);
    rep(i, n)
    {
        rep(j, m)
        {
            cout << mat[i][j] << " ";
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
