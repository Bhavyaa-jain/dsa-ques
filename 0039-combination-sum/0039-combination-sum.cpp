
class Solution {
public:
    void solve(vector<int>& arr, int target,
               int idx, vector<int>& ans,
               vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }
        if (idx == arr.size()) {
            return;
        }
        if (arr[idx] <= target) {

            ans.push_back(arr[idx]);

            solve(arr, target - arr[idx],
                  idx, ans, result);
            ans.pop_back();
        }
        solve(arr, target, idx + 1,
              ans, result);
    }

    vector<vector<int>> combinationSum(vector<int>& arr,
                                       int target) {

        vector<vector<int>> result;
        vector<int> ans;

        solve(arr, target, 0, ans, result);

        return result;
    }
};
