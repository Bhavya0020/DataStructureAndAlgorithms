// Problem Link: https://leetcode.com/problems/sort-colors/

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

void sortColors(vector<int> &ar)
{
    int n = ar.size();           // get the size of the array
    int l = 0, m = 0, h = n - 1; // initialized 3 variables to keep a track of all 0s 1s and 2s
    // after the sorting is done [0 - l-1] will contain 0s, [l - m-1] will contain 1s, [h+1 - n-1] wil contain 2s
    while (m <= h)
    {
        // Case 1:
        if (ar[m] == 0)
        {
            // if ar[m] is 0 then we can say for sure that it should be swapped with ar[l] as [0 - l-1] contains 0s
            swap(ar[l], ar[m]);
            l++;
            m++;
        }
        else if (ar[m] == 1)
        {
            // if ar[m] is 1 then we can say for sure that it should be moved to next index as [l - m-1] contains 1s
            m++;
        }
        else if (ar[m] == 2)
        {
            // if ar[m] is 2 then we can say for sure that it should be swapped with ar[h] as [h+1 - n-1] contains 2s
            swap(ar[m], ar[h]);
            h--;
        }
    }
}

void testcase()
{
    int n, i;
    cin >> n;
    vi ar(n);
    // Input the array
    rep(i, n)
    {
        cin >> ar[i];
    }
    sortColors(ar); // Function to sort array
    // Display the array
    rep(i, n)
    {
        cout << ar[i] << " ";
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
