/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/ransom-note/
 */

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

class Solution {
	/*
	time: O(m+n). 50 ms.
	*/
	public boolean canConstruct(String ransomNote, String magazine) {
		Map<Character, Integer> ransomDict = new HashMap<Character, Integer>();
		int len = ransomNote.length();
		for(int i = 0; i < len; ++i) {
			if(ransomDict.get(ransomNote.charAt(i)) != null) {
				ransomDict.put(ransomNote.charAt(i), ransomDict.get(ransomNote.charAt(i)) + 1);	//OK
			}
			else{
				ransomDict.put(ransomNote.charAt(i), 1);
			}
		}

		len = magazine.length();
		for(int i = 0; i < len; ++i) {
			if(ransomDict.get(magazine.charAt(i)) != null) {
				if(ransomDict.get(magazine.charAt(i)) == 0)
					continue;
				ransomDict.put(magazine.charAt(i), ransomDict.get(magazine.charAt(i)) - 1);	//OK
			}
		}

		Iterator it = ransomDict.keySet().iterator();
		Character ch;
		while(it.hasNext()){
			ch = (Character)it.next();
			//ch = it.next();	// error: incompatible types: Object cannot be converted to char
			if(ransomDict.get(ch) != 0)
				return false;
		}

		return true;
    }
}
public class num383 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		System.out.format("result = %s\n", sl.canConstruct("a", "b"));
		System.out.format("result = %s\n", sl.canConstruct("aa", "ab"));
		System.out.format("result = %s\n", sl.canConstruct("aa", "aab"));
		System.out.format("result = %s\n", sl.canConstruct("bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"));
	}
}
