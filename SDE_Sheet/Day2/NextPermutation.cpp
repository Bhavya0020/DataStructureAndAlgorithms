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

// BuiltIn STL
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

// Logic
void nextPermutationLogic(vector<int> &nums)
{
    int n = nums.size(),i, j;
    for(i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i+1])
            break;
    }
    if(i < 0)
        reverse(nums.begin(), nums.end());
    else{
        for(j = n - 1; j > i; j--){
            if(nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
}

void testcase()
{
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
