/**
 * @FileName: num1.java
 * @Author: lxw
 * @Date: 2014-12-30
 * @Usage: LeetCode num 1.
 */
class Solution {
	public char findTheDifference(String s, String t) {
		int num = 0;
		int length = s.length();
		int i = 0;
		for(; i < length; ++i){
			num += (t.charAt(i) - s.charAt(i));
		}
		num += t.charAt(i);
		return (char)num;
	}
}
public class num389 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		System.out.format("result = %c\n", sl.findTheDifference("bbbacde", "bdbcabeb"));
	}
}
