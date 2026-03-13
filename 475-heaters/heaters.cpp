class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(heaters.begin(), heaters.end());

        int radius = 0;

        for(int house : houses){

            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int right = (it == heaters.end()) ? INT_MAX : *it - house;
            int left  = (it == heaters.begin()) ? INT_MAX : house - *(it-1);

            int dist = min(left, right);

            radius = max(radius, dist);
        }

        return radius;
    }
};