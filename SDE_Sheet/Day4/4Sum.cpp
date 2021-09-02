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

vector<vector<int>> fourSum(vector<int> &ar, int sum)
{
    int n = ar.size();
    sort(ar.begin(), ar.end());
    vector<vector<int>> ans;
    //         keep track of ar[a]
    for (int i = 0; i < n; i++)
    {
        //             keep track of ar[b]
        for (int j = i + 1; j < n; j++)
        {
            //                 keep track of ar[c]
            int t = sum - ar[i] - ar[j];
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                if (ar[l] + ar[r] == t)
                {
                    ans.push_back({ar[i], ar[j], ar[l], ar[r]});
                    l++;
                    r--;
                }
                else if (ar[l] + ar[r] < t)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase((unique(ans.begin(), ans.end())), ans.end());
    return ans;
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
    vii ans = fourSum(ar, t);
    rep(i, ans.size())
    {
        print(ans[i][0]) << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << "\n";
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
