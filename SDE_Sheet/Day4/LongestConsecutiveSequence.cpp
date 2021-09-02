// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
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

int longestConsecutiveSequence(vector<int> &ar)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < ar.size(); i++)
    {
        mp[ar[i]] = i;
    }
    int ans = 0, mx_sf = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        mx_sf = 0;
        if (mp.find(ar[i] - 1) != mp.end())
        {
            continue;
        }
        else
        {
            int x = ar[i];
            while (mp.find(x) != mp.end())
            {
                x++;
                mx_sf++;
            }
            ans = max(ans, mx_sf);
        }
    }
    return ans;
}

void testcase()
{
    int n, i;
    input(n);
    vi ar(n);
    rep(i, n)
    {
        input(ar[i]);
    }
    cout << longestConsecutiveSequence(ar) << "\n";
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
