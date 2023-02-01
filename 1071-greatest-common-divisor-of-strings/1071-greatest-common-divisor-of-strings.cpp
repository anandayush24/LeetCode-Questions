class Solution {
public:
    int solution(int num1, int num2){
        if(num2==0){
            return num1;
        }
        return gcd(num2, num1%num2);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1){
            return "";
        }
        if(str1.size()<str2.size()){
            swap(str1, str2);
        }
        int n= solution(str1.size(), str2.size());
        return str1.substr(0,n);
    }
};