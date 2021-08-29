// Problem Link: https://leetcode.com/problems/powx-n/

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

// Recursive
double power(double x, long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    double ans = myPow(x, n / 2);
    if (n & 1)
    {
        return ans * ans * x;
    }
    else
    {
        return ans * ans;
    }
}
// Iterative
double poweritr(double x, long n)
{
    if (n == 0)
    {
        return 1;
    }
    double ans = 1;
    while (n >= 1)
    {
        if (n & 1)
        {
            ans = ans * x;
        }
        n = n / 2;
        ;
        x *= x;
    }
    return ans;
}
double myPow(double x, int n)
{
    bool flag = false;
    long y = n;
    if (n < 0)
    {
        flag = true;
        y *= -1;
    }
    double ans = power(x, y);
    if (flag)
    {
        return (double)(1.0 / ans);
    }
    else
    {
        return ans;
    }
}

void testcase()
{
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << "\n";
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
