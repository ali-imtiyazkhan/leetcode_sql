class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int x:nums) mp[x]++;

        int ans = 1;

        if(mp.count(1)){
            int c = mp[1];
            ans = max(ans, c - !(c&1));
        }

        for(auto &[x,_]: mp){
            if(x==1) continue;

            long long cur = x;
            int curAns = 0;

            while(mp[cur] >= 2){
                curAns += 2;

                long long nxt = cur*cur;

                if(!mp.count(nxt)){
                    curAns--;
                    break;
                }

                cur = nxt;
            }

            if(mp[cur] == 1) curAns++;

            ans = max(ans, curAns);
        }

        return ans;
    }
};