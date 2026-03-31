#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] < minPrice) {
                minPrice = prices[i];  // update minimum
            }
            
            int profit = prices[i] - minPrice;

            if (profit > maxProfit) {
                maxProfit = profit;   // update max profit
            }
        }

        return maxProfit;
    }
};