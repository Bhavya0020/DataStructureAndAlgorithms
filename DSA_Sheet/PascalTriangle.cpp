class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int j = 0, b = 1;
            vector<int> v;
            while(j <= i){
                if(j == 0 || i == j)
                {
                    b = 1;
                }
                else{
                    b = ((i - j + 1)*b) / j;
                }
                v.push_back(b);
                j++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};
