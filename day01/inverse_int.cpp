//
// Created by 26432 on 2024/6/13.
//
/*
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
*/
# include "iostream"
# include <queue>
class Solution {
public:
    int reverse(int x) {
        bool is_negative = false;
        if(x<0)
            is_negative = true;
        queue<int> q;
        while(x!=0){
            q.push(x%10);
            x/=10;
        }
        long long int reverse_x =0;
        while(!q.empty()){
            int digit = q.front();
            q.pop();
            reverse_x = reverse_x * 10 + digit;
        }
        if(reverse_x < -2147483648 || reverse_x > 2147483647){
            return 0;
        }
        return reverse_x;
    }
};

int main(){
    Solution s;
    s.reverse(1234);
}