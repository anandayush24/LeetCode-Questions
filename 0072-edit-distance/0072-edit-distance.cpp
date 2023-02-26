class Solution {
private:
    unordered_map<string, int> dp;

    int fnc(int i, int j, string word1, string &word2) {
        if (word1 == word2) {
            return 0;

        } else if (word2.length() == 0) {
            return word1.length();

        } else if (word1.length() == 0) {
            return word2.length();

        } else if (j >= word2.length()) {
            return word1.length() - j;

        } else if (i >= word1.length()) {
            return word2.length() - i;

        } else if (dp.find(word1) != dp.end()) {
            return dp[word1];

        } else if (word1[i] == word2[j]) {
            return dp[word1] = fnc(i + 1, j + 1, word1, word2);

        } else {
            string replacedCharWord1 = word1;
            string deletedCharWord1 = word1;
            string insertedCharWord1 = word1;

            string _char = "";
            _char += word2[j];

            replacedCharWord1.replace(i, 1, _char);
            deletedCharWord1.replace(i, 1, "");
            insertedCharWord1.insert(i, _char);

            int _replace = fnc(i + 1, j + 1, replacedCharWord1, word2);
            int _delete = fnc(i, j, deletedCharWord1, word2);
            int _insert = fnc(i + 1, j + 1, insertedCharWord1, word2);

            return dp[word1] = 1 + min({_replace, _delete, _insert});
        }
    }

public:
    int minDistance(string word1, string word2) {
        return fnc(0, 0, word1, word2);
    }
};