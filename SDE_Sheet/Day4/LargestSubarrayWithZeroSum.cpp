// Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

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

int LargestSubarrayWithZeroSum(vector<int> &ar)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
        if (sum == 0)
        {
            ans = i + 1;
        }
        else
        {
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
            else
            {
                ans = max(ans, i - mp[sum]);
            }
        }
    }
    return ans;
}

void testcase()
{
    int i, n;
    input(n);
    vi ar(n);
    rep(i, n)
    {
        input(ar[i]);
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
