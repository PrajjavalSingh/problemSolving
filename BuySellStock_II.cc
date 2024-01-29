//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const auto size = prices.size();
        if ( size <=1 )
            return 0;

        auto minprice = prices[0];
        auto totalprofit = 0;
        auto profit = 0;
        
        for ( int idx=1; idx<size; idx++ )
        {
            const auto currprice = prices[idx];
            if ( currprice < prices[idx-1] )
            {
                totalprofit += profit;
                minprice = currprice;
                profit = 0;
            }

            const auto currprof = currprice - minprice; 
            if ( currprof > profit )
                profit = currprof;

            if ( currprice < minprice )
                minprice = currprice;
        }
        
        if ( profit != 0 )
            totalprofit += profit;
            
        return totalprofit;
    }
};
