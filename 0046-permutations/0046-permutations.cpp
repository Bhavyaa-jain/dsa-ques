class Solution {
public:

    void getPermutations(vector<int>& nums, vector<int>& ans,
                         vector<vector<int>>& allPermutations,
                         vector<bool>& used) {

        if(ans.size() == nums.size()) {
            allPermutations.push_back(ans);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!used[i]) {

                // Include element
                ans.push_back(nums[i]);
                used[i] = true;

                getPermutations(nums, ans, allPermutations, used);

                // Backtracking
                ans.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> allPermutations;
        vector<int> ans;
        vector<bool> used(nums.size(), false);

        getPermutations(nums, ans, allPermutations, used);

        return allPermutations;
    }
};