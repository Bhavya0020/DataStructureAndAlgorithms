// Problem Link: https://leetcode.com/problems/merge-intervals/

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

vector<vector<int>> merge(vector<vector<int>> &ar)
{
    vector<vector<int>> ans;
    // sort the array to keep the elements in an ascending order 
    // necessary for cases like [[1,4], [0,4]] 
    sort(ar.begin(), ar.end());
    int i = 1, st = ar[0][0], ed = ar[0][1];
    for (i = 1; i < ar.size(); i++)
    {
        // check if start of array element is less than or equal to the ending element 
        if (ar[i][0] <= ed)
        {
            // the ending element will be the maximum of these 2
            // case: [[1,4],[2,3]]
            ed = max(ed, ar[i][1]);
        }
        else
        {
            // add elements to ending array and update start and end variables
            ans.push_back({st, ed});
            st = ar[i][0];
            ed = ar[i][1];
        }
    }
    ans.push_back({st, ed});
    return ans;
}

void testcase()
{
    int n;
    cin >> n;
    vii a,ar(n, vi(2, 0));
    int i;
    rep(i, n)
    {
        cin >> ar[i][0] >> ar[i][1];
    }
    ar = merge(ar);
    rep(i, ar.size()){
        cout << "[" << ar[i][0] << " " << ar[i][1] << "] ";
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
