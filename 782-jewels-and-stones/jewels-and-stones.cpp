class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char,int> mp;

        for(char c : jewels){
            mp[c]++;
        }

        int count = 0;

        for(char ch : stones){
            if(mp.count(ch)){
                count++;
            }
        }

        return count;
    }
};