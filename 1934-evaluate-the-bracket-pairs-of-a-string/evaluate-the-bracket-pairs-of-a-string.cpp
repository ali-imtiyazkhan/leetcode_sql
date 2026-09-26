class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        int i = 0;

        while (i < s.length()) {
            if (s[i] == '(') {
                i++;

                string key = "";

                while (s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }

               if(mp.find(key) != mp.end()){
                   for(int i = 0; i < mp[key].size();i++){
                    ans.push_back(mp[key][i]);
                   }
               }else{
                ans.push_back('?');
               }
               i++;

               continue;    

            } else {
                ans.push_back(s[i]);
                i++;
            }
        }

        return ans;
    }
};