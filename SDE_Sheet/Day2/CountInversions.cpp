// Problem Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

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

long long merge(long long arr[], long long lo, long long mid, long long hi)
{
    long long n1 = mid - lo + 1, i, j, k = lo;
    long long int inv_Count = 0;
    long long n2 = hi - mid;
    long long L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[i + lo];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
        {
            inv_Count += n1 - i;
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    return inv_Count;
}
long long mergeS(long long arr[], long long lo, long long hi)
{
    long long int inv_Count = 0, mid;
    if (hi > lo)
    {
        mid = lo + ((hi - lo) / 2);
        inv_Count += mergeS(arr, lo, mid);
        inv_Count += mergeS(arr, mid + 1, hi);
        inv_Count += merge(arr, lo, mid, hi);
    }
    return inv_Count;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long ans = mergeS(arr, 0, N - 1);
    return ans;
}

void testcase()
{
    long long N;
    cin >> N;

    long long A[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << inversionCount(A, N) << endl;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto start = high_resolution_clock::now();
    ll t;
    cin >> t;
    while (t--)
        testcase();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    return 0;
}
