class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for(string &pattren : patterns){
            if(word.find(pattren) != string::npos){
                count++;
            }
        }
        return count;
    }
};