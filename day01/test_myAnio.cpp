//
// Created by 26432 on 2024/6/13.
//
# include "iostream"
class Solution {
public:
    int myAtoi(std::string s) {
        int result = 0, sign=1, i=0;
        while(s[i]==' '){
            i++;
        }
        if (s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        while(s[i]>='0' && s[i]<='9'){
            int digit = s[i]-'0'; //计算ASCII码
//            std::cout<<digit<<std::endl;
            if (result>2147483647/10 || (result==2147483647/10 && digit>7)){ //这个地方误操作将result==写成了result=
                return sign==1? 2147483647:-2147483647;
            }
            result = result * 10 + digit;
            i++;
//            std::cout<<"\ndigit="<<digit<<std::endl;
//            std::cout<<"\nresult="<<result<<std::endl;
        }
        result = result * sign;
        return result;
    }
};

int main(){
    Solution s;
    std::cout << "myAtoi(\" 42\") = " << s.myAtoi("42") << std::endl;
}