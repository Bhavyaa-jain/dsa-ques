class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char ch = chars[read];
            int start = read;

            while (read < n && chars[read] == ch) {
                read++;
            }

            int count = read - start;

            chars[write++] = ch;

            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        chars.resize(write);
        return write;
    }
};