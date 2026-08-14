class Solution {
public:

    bool isPossible(vector<int> &position, int m, int maxDistance){
        int balls = 1;
        int lastPosition = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i]- lastPosition >= maxDistance){
                balls++;
                lastPosition = position[i];
            }
            if(balls == m){
                return true;
            }
        }       
    return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int st = 0, end = position[position.size()-1] - position[0] , ans = -1;
        while(st<= end){
            int mid = st + (end - st)/2;
            if(isPossible(position,m,mid)){
                ans = mid;
                st = mid+1;
            } else{
                end = mid-1;
            }
        }
       return ans; 
    }
    
};