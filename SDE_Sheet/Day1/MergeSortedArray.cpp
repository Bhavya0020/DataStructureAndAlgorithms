// Problem Link: https://leetcode.com/problems/merge-sorted-array/ 

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

int newGap(int n)   // This is a function used to calculate the next gap 
{
    if (n <= 1)
    {
        return 0;
    }
    return (n / 2) + (n % 2);
}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // To merge 2 array without using extra space we need to use gap method
    // In gap method we have a gap of m(size of first array) and every ith and (i + gap)th element is compared 
    // In the end we will get a merged sorted array 
    int j = 0;
    for (int i = m; i < m + n; i++, j++)
    {
        nums1[i] = nums2[j];
    }
    for (int gap = m; gap != 0; gap = newGap(gap))
    {
        for (int i = 0; i + gap < n + m; i++)
        {
            if (nums1[i] > nums1[i + gap])
            {
                swap(nums1[i], nums1[i + gap]);
            }
        }
    }
}

void testcase()
{
    int n, m, x, i;
    cin >> n >> m;
    vector<int> nums1, nums2;
    rep(i, n)
    {
        cin >> x;
        nums1.push_back(x);
    }
    rep(i, m)
    {
        cin >> x;
        nums2.push_back(x);
    }
    nums1.resize(n + m);
    merge(nums1, n, nums2, m);
    rep(i, n + m)
    {
        cout << nums1[i] << " ";
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
