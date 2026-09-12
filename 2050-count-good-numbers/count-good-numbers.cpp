class Solution {
public:

    long long power(long long base, long long exp, long long MOD){
        long long ans = 1;

        while(exp > 0){
            if(exp % 2 == 1){
             ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            exp /= 2;
        }
        return ans;
    }


    int countGoodNumbers(long long n) {

        long long MOD = 1e9 + 7;
        long long evenPosition = (n + 1)/2;
        long long oddPosition = n / 2;

        long long evenWays = power(5,evenPosition,MOD);
        long long oddWays = power(4,oddPosition,MOD);

        return (evenWays*oddWays) % MOD;

    }
};