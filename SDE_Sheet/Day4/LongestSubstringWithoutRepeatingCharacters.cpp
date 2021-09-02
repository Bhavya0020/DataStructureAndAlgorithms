// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long int
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REPR(i,k,n) for (i = k; i >= n; i--) 
#define pii pair<int,int>
#define PB push_back
#define input(n) cin >> (n)
#define print(n) cout << (n)

int LongestSubstringWithoutRepeatingCharacters(string s){
    unordered_map<int,int> mp;
    int l = 0, r = 0, len = 0;
    while(r < s.length()){
        if(mp.find(s[r]) != mp.end()){
            l = max(mp[s[r]] + 1, l);
        }
        mp[s[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

void testcase(){
    
}

int main(){
    ios_base :: sync_with_stdio(false);
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
