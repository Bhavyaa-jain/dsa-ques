class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int maxCapacity) {
        int n = weights.size();
        int currentWeight = 0;
        int requiredDays = 1;

        for(int i = 0; i < n; i++) {
            if(currentWeight + weights[i] <= maxCapacity) {
                currentWeight += weights[i];
            } else {
                requiredDays++;
                currentWeight = weights[i];
            }
        }

        return requiredDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxWeight = 0;

        for(int i = 0; i < n; i++) {
            sum += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }

        int st = maxWeight;
        int end = sum;
        int ans = -1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isPossible(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};