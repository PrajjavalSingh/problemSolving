//https://leetcode.com/problems/count-primes/
class Solution {
public:
    int countPrimes(int n) 
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
    
        for ( int pidx = 2; pidx * pidx <= n; pidx++) 
        {
            if (prime[pidx] == true) 
            {
                for (int idx = pidx * pidx; idx <= n; idx += pidx)
                    prime[idx] = false;
            }
        }
    
        int count = 0;
        for (int kidx = 2; kidx<n; kidx++)
            if ( prime[kidx] )
                count++;
        
        return count;
    }
};
