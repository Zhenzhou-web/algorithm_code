class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>> mapres;
        for(auto &str:strs){
            string count(26,0);
            for(auto &cha:str){
                count[cha-'a']+=1;

            }
                mapres[count].push_back(str);            
        }
        for(auto&ses:mapres){
            res.push_back(ses.second);
        }
        return res;
    }
};
