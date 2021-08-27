// Problem Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

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

// Sorting Method
vector<int> fun1(vi &ar, int n)
{
    // sort the array in ascending order
    sort(ar.begin(), ar.end());
    vi ans;
    int i = 0, x = ar[0];
    REP(i, 1, n - 1)
    {
        if (ar[i] == ar[i - 1])
        {
            ans.push_back(ar[i]);
        }
        if(ar[i] == x){
            x++;
        }
    }
    ans.PB(x);
    return ans;
}

// Count Array Method
vector<int> fun2(vi &ar, int n)
{
    vi t(n + 1, 0);
    int i = 0;
    rep(i, n)
    {
        t[ar[i]]++;
    }
    vi ans;
    REP(i, 1, n)
    {
        if (ar[i] != 1)
        {
            ans.push_back(ar[i]);
        }
    }
    return ans;
}

// Mark And place Method
vector<int> fun3(vi &ar, int n)
{
    int i;
    vi ans;
    rep(i, n)
    {
        if (ar[abs(ar[i]) - 1] > 0)
        {
            ar[abs(ar[i]) - 1] -= ar[abs(ar[i]) - 1];
        }
        else
        {
            ans.PB(abs(ar[i]));
        }
    }
    rep(i, n)
    {
        if (ar[i] > 0)
        {
            ans.PB(i + 1);
        }
    }
}

// Make Equation
vi fun4(vi &ar, int n)
{
    ll m = n;
    ll a = 0, b = 0;
    // a will keep sum of natural numbers from 1 to n
    a = (m * (m + 1)) / 2;
    // b will keep sum of square of natural numbers from 1 to n
    b = (m * (m + 1) * (2 * m + 1)) / 6;
    int i;
    rep(i, n)
    {
        a -= (ll)ar[i];
        b -= ((ll)ar[i] * (ll)ar[i]);
    }
    // say x is missing number and y is repeating number
    // now a will be x - y and b will be x^2 - y^2
    // x = a + b/a and y = x - a
    ll x = a + b / a, y = x - a;
    return {(int)x, (int)y};
}

// Simple Hashing
vi fun5(vi &ar, int n)
{
    map<int, int> mp;
    rep(i, n)
    {
        mp[ar[i]]++;
    }
    vi ans;
    for (auto x : mp)
    {
        // Repeating
        if (x.second > 1)
        {
            ans.PB(x.first);
        }
    }
    REP(i, 1, n)
    {
        // Missing
        if (mp.find(i) == mp.end())
        {
            ans.PB(i);
        }
    }
    return ans;
}

// XOR Method
vi fun6(vi &A)
{
    int x = 0;
    for (int i : A)
    {
        x = (x ^ i);
    }
    for (int i = 1; i <= A.size(); i++)
    {
        x = (x ^ i);
    }
    int rep = 0, mis = 0;
    int rmb = floor(log2(x));
    for (int i : A)
    {
        if (((1 << rmb) & i))
        {
            mis = (mis ^ i);
        }
        else
        {
            rep = (rep ^ i);
        }
    }
    for (int i = 1; i <= A.size(); i++)
    {
        if (((1 << rmb) & i))
        {
            mis = (mis ^ i);
        }
        else
        {
            rep = (rep ^ i);
        }
    }
    return {mis, rep};
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
    vi x;
    x = fun1(ar, n);
    cout << x[0] << " " << x[1] << "\n";
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
