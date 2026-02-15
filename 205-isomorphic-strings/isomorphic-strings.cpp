class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        for(int i = 0; i < s.length(); i++) {
            
            char c1 = s[i];
            char c2 = t[i];
            
            // Check s -> t mapping
            if(map1.count(c1)) {
                if(map1[c1] != c2)
                    return false;
            }
            else {
                map1[c1] = c2;
            }
            
            // Check t -> s mapping
            if(map2.count(c2)) {
                if(map2[c2] != c1)
                    return false;
            }
            else {
                map2[c2] = c1;
            }
        }
        
        return true;
    }
};
