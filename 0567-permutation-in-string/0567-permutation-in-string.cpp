class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return false;

        int a[26] = {0};
        int b[26] = {0};

        for(char c : s1)
            a[c - 'a']++;

        for(int i = 0; i < s1.size(); i++)
            b[s2[i] - 'a']++;

        for(int i = s1.size(); i < s2.size(); i++) {

            if(equal(a, a + 26, b))
                return true;

            b[s2[i] - 'a']++;
            b[s2[i - s1.size()] - 'a']--;
        }

        return equal(a, a + 26, b);
    }
};