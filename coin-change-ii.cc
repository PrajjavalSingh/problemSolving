//https://leetcode.com/problems/coin-change-ii/editorial/

class Solution {
public:
    vector<int> coins;
    vector<vector<int>> memo;

    int numberOfWays(int i, int amount) {
        if (amount == 0) {
            return 1;
        }
        if (i == coins.size()) {
            return 0;
        }
        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        if (coins[i] > amount) {
            return memo[i][amount] = numberOfWays(i + 1, amount);
        }

        memo[i][amount] = numberOfWays(i, amount - coins[i]) + numberOfWays(i + 1, amount);
        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return numberOfWays(0, amount);
    }
};




//Bottom up aaproach
//
class Solution {
public:

    int change(int amount, vector<int>& coins) 
    {
        const int sz = coins.size();
        vector<vector<int>> calcarray( sz+1, vector<int>(amount+1) );
        for ( int idx=0; idx< sz; idx++ )
        {
            calcarray[idx][0] = 1;
        } 

        for ( int jidx=sz-1; jidx>=0; jidx -- )
        {
            for ( int kidx=1; kidx <=amount; kidx++ )
            {
                if ( coins[jidx] > kidx )
                    calcarray[jidx][kidx] = calcarray[jidx+1][kidx];
                else
                    calcarray[jidx][kidx] = calcarray[jidx+1][kidx] + calcarray[jidx][kidx-coins[jidx]];
            }
        }

        return calcarray[0][amount];
    }
};





//Next soln
class Solution {
public:


    int change(int amount, vector<int>& coins) 
    {
        if ( amount < 0 )
            return 0;
        else if ( amount == 0 )
            return 1;
        sort(coins.begin(),coins.end());
        if ( coins[0] > amount )
            return 0;
        else if ( coins[0] == amount )
            return 1;
        
        auto it = std::find_if(coins.begin(),coins.end(),[=](auto coin){return coin > amount; });
        if ( it != coins.end() )
            coins.erase( it, coins.end() );
        int ret = 0;
        
        const int size = coins.size();
        vector<int> arr(amount+1);
        arr[0] = 1;
        for ( int idx=size-1; idx>=0; idx-- )
        {
            for (int jidx=coins[idx]; jidx<=amount; jidx++ )
            {
                arr[jidx] +=arr[jidx-coins[idx]];
            }
        }


        return arr[amount];
    }
};
