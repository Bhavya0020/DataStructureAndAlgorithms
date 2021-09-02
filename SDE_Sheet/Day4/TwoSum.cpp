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

vector<int> twoSum(vector<int> &ar, int sum)
{
    map<int, int> mp;
    for (int i = 0; i < ar.size(); i++)
    {
        mp.insert({ar[i], i});
    }
    for (int i = 0; i < ar.size(); i++)
    {
        if (mp.find(sum - ar[i]) != mp.end())
        {
            int x = mp[sum - ar[i]];
            if (x != i)
            {
                return {min(x, i), max(i, x)};
            }
        }
    }
    return {-1, -1};
}

void testcase()
{
    int n, i, t;
    input(n);
    vi ar(n);
    rep(i, n)
    {
        input(ar[i]);
    }
    input(t);
    vi ans = twoSum(ar, t);
    print(ans[0]) << " " << ans[1] << "\n";
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
