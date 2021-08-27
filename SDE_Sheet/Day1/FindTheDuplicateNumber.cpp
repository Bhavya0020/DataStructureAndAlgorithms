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

// Visited Array Method
int findDuplicate1(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> v(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!v[nums[i] - 1])
        {
            v[nums[i] - 1] = true;
        }
        else
        {
            return nums[i];
        }
    }
    return 1;
}

// Tortoise Method
int findDuplicate2(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
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
    cout << findDuplicate1(ar);
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
