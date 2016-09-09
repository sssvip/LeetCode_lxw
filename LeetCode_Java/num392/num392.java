/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/is-subsequence/
 */

/*
Time: O(len(s) + len(t))
*/
class Solution {
    public boolean isSubsequence(String s, String t) {
    	int sLen = s.length();
    	int tLen = t.length();
    	if(sLen == 0)
    		return true;
    	else if(sLen > tLen)
    		return false;
    	else if(s.equals(t))
    		return true;

    	int sIndex = 0;
    	int tIndex = 0;

    	/*
    	//Bad
    	while(sIndex < sLen && tIndex < tLen){
	    	while(tIndex < tLen && t.charAt(tIndex) != s.charAt(sIndex)){
	    		++tIndex;
	    	}
	    	if(tIndex < tLen){
	    		++tIndex;
	    		++sIndex;
	    	}
	    }
	    */

	    //Good
    	while(sIndex < sLen && tIndex < tLen){
	    	if(t.charAt(tIndex) == s.charAt(sIndex)){
	    		++sIndex;
	    	}
	    	++tIndex;
	    }

	    /*
	    //Bad
	    if(sIndex == sLen)
	    	return true;
	    else
	    	return false;
	    */
	    return sIndex == sLen;	//Good
    }
}

public class num392 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		System.out.format("result = %s\n", sl.isSubsequence("axe", "abdbcabeb"));
	}
}
