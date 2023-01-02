class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps=0;
        for(int i=0;i<word.length();i++){
            char temp = word[i];
            if(isupper(temp))
                caps++;
        }
        
        if(caps == 0 || caps == word.length()){ 
            return true; 
        }
        if(caps == 1 && isupper(word[0])){ 
            return true; 
        }
        
        return false;
    }
};