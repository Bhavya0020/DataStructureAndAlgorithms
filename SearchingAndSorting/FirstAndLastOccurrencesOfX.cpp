// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> find(int ar[], int n, int x)
{
    // code here
    if (binary_search(ar, ar + n, x))
    {
        int first = lower_bound(ar, ar + n, x) - ar;
        int second = upper_bound(ar, ar + n, x) - ar;
        return {first, second - 1};
    }
    return {-1, -1};
}