//
// Created by 26432 on 2024/6/13.
//
/* Problem Describe: ASCII to Integer(Atio)
 * 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。
    1.空格：读入字符串并丢弃无用的前导空格（" "）
    2.符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
    3.转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
    4.舍入：如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，使其保持在这个范围内。
      具体来说，小于 −2^31 的整数应该被舍入为 −2^31 ，大于 2^31 − 1 的整数应该被舍入为 2^31 − 1 。
返回整数作为最终结果。*/
# include <iostream>
class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1, result = 0; //把符号放在最后一位上
        while (s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;

        while (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0'; //0的ASCII值是48，相当于做的是ASCII码的加减法
//            std::cout<<"\n i = "<<i<<" --digit="<<digit<<std::endl;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) //signed-int 2^31-1=2147483647
                return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + digit;
            i++;
        }
        return result * sign;
    }
};


int main() {
    Solution s;
    // 测试一些输入情况
    std::cout << "myAtoi(\" 42\") = " << s.myAtoi("42") << std::endl;
    std::cout << "myAtoi(\"   -42\") = " << s.myAtoi("   -42") << std::endl;
    std::cout << "myAtoi(\"4193 with words\") = " << s.myAtoi("4193 with words") << std::endl;
    std::cout << "myAtoi(\"words and 987\") = " << s.myAtoi("words and 987") << std::endl;
    std::cout << "myAtoi(\"-91283472332\") = " << s.myAtoi("-91283472332") << std::endl;
    std::cout << "myAtoi(\"91283472332\") = " << s.myAtoi("91283472332") << std::endl;
    std::cout << "myAtoi(\"\") = " << s.myAtoi("") << std::endl;
    std::cout << "myAtoi(\"00042\") = " << s.myAtoi("00042") << std::endl;
    std::cout << "myAtoi(\"-000000000000001\") = " << s.myAtoi("-000000000000001") << std::endl;
    std::cout << "myAtoi(\"+-12\") = " << s.myAtoi("+-12") << std::endl;
    std::cout << "myAtoi(\"abc1234abc\") = " << s.myAtoi("abc1234abc") << std::endl;
    std::cout << "myAtoi(\"123-456\") = " << s.myAtoi("123-456") << std::endl;
    return 0;
}