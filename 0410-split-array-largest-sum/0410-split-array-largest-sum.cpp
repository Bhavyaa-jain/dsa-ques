class Solution {
public:

    bool isValid(vector<int>& nums, int k,int maxSum){
        int n = nums.size();
        int subarrays = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= maxSum){
                sum+= nums[i];
            } else {
                subarrays++;
                sum = nums[i];
            }
        }
        return subarrays <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n =  nums.size();
        int st = 0, end = 0;
        for(int i = 0; i < n; i++) {
            st = max(st, nums[i]);
            end += nums[i];
        }

        int ans = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isValid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};
