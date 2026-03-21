class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

        sort(ages.begin(), ages.end());

        int n = ages.size();
        int left = 0, right = 0;
        int result = 0;

        for(int i = 0; i < n; i++){

            if(ages[i] < 15) continue;

            while(ages[left] <= 0.5 * ages[i] + 7)
                left++;

            while(right + 1 < n && ages[right + 1] <= ages[i])
                right++;

            result += (right - left);
        }

        return result;
    }
};