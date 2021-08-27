// Problem Link: https://leetcode.com/problems/maximum-subarray/

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

// Time Complexity O(n ^ 3)
int method1(vi &ar)
{

    // we have to find the maximum subarray in the given array
    // the brute force approach will be to generate all the subarrays and then find the max sum
    // but this approach will require O(n ^ 3) Time which is not optimal

    // for starting index
    int i, j, k, ans = INT_MIN;
    rep(i, ar.size())
    {
        // for ending index
        REP(j, i, ar.size())
        {
            // for finding sum
            int sum = 0;
            REP(k, i, j)
            {
                sum += ar[k];
            }
            ans = min(ans, sum);
        }
    }
    return ans;
}

// Time Complexity O(n ^ 2)
int method2(vi &ar)
{
    // The brute force method can be optimized using a simple observation
    // in the 3rd loop we are calculating the sum for i to j
    // this loop can be avoided is we pre compute the solution

    int i, j, k, ans = INT_MIN;
    // precompution
    vi sum(ar.size(), 0);
    rep(i, ar.size())
    {
        sum[i] = ar[i];
        if (i != 0)
        {
            sum[i] += sum[i - 1];
        }
    }
    // for starting index
    rep(i, ar.size())
    {
        // for ending index
        REP(j, i, ar.size())
        {
            // for finding sum
            int s = 0;
            s = sum[j] - sum[i - 1];
            ans = min(ans, s);
        }
    }
    return ans;
}

// Time Complextiy O(n)
int maxSubArray(vector<int> &nums)
{
    // Kadane's algorithm is the most optimal solution for finding maximum subarray sum
    // the idea is simple keep a variable(say s) for finding the sum so far in the array
    // if s > sum then we can say that this can possibly be the largest sum for update it (sum = s)
    // if s < 0 then we can say that add next array element is definately not going to give the maximum subarray sum 
    // so we can change it to 0(s = 0)
    int s = 0, sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        s += nums[i];
        if (s > sum)
        {
            sum = s;
        }
        if (s < 0)
        {
            s = 0;
        }
    }
    return sum;
}

void testcase()
{
    int n, i;
    cin >> n;
    vi ar(n);
    // Input an array
    rep(i, n)
    {
        cin >> ar[i];
    }
    cout << maxSubArray(ar);
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
