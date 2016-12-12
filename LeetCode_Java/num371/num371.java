/*
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/counting-bits/
 */

/*
Num 371: Sum of Two Integers
Source: https://leetcode.com/problems/sum-of-two-integers/

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

class Solution {
    //This method is not fit for Python.
    public int getSum_Java_YES_Python_NO(int a, int b) {
        int carry = 0;
        int andAB = a & b;  //NOTE: int OK? yes, int OK.
        int orAB = a | b;
        int result = 0; //NOTE: overflow may happen getSum(a, b)
        for(int i = 0; i < 32; ++i){
            int one = 1 << i;
            //一定要注意：按位运算符(&,|,!)优先级高于逻辑运算符（and, or)，但都低于==和!=;逻辑运算符not的优先级很高，高于前述所有运算符;赋值运算符=的优先级很低，低于前述所有的运算符.
            if((andAB & one) == one){ //(1, 1) lxw NOTE: the parenthesis is essential here.
                if(carry == 1){
                    result |= one;
                }
                carry = 1;
            }
            else if((orAB & one) == one){ //(1, 0) or (0, 1)
                if(carry == 0){
                    result |= one;
                }
            }
            else{   //(0, 0)
                if(carry == 1){
                    result |= one;
                    carry = 0;
                }
            }
        }

        return result;
    }

    //References: http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
    public int getSum(int a, int b){
        int carry = 0;
        while(b != 0){
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}

public class num371 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.format("sol.getSum(1, 2): %d\n", sol.getSum(1, 2));
        System.out.format("sol.getSum(4, -3): %d\n", sol.getSum(4, -3));
        System.out.format("sol.getSum(3, -3): %d\n", sol.getSum(3, -3));
        System.out.format("sol.getSum(3, -4): %d\n", sol.getSum(3, -4));
        System.out.format("sol.getSum(2147483647, 2147483647): %d\n", sol.getSum(2147483647, 2147483647));  //overflow
    }
}
