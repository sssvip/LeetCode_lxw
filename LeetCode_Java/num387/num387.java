/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

class Solution {
	/*
	Time: O(n). 91 ms.
	*/
	public int firstUniqChar(String s) {
		Map<Character, Integer> indexDict = new HashMap<Character, Integer>();
		int len = s.length();
		for(int i = 0; i < len; ++i) {
			if(indexDict.get(s.charAt(i)) != null) {
				indexDict.put(s.charAt(i), -1);	//OK
				//indexDict[s.charAt(i)] = -1;	//NO
			}
			else{
				indexDict.put(s.charAt(i), i);
			}
		}
		int minIndex = len;
		Iterator it = indexDict.keySet().iterator();
		int temp;
		while(it.hasNext()){
			//it.next()	//key
			temp = indexDict.get(it.next());
			if(temp != -1)
				minIndex = minIndex > temp ? temp : minIndex;
		}
		return minIndex == len ? -1 : minIndex;
    }
}
public class num387 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		System.out.format("result = %d\n", sl.firstUniqChar("leeltcotdecotd"));
		System.out.format("result = %d\n", sl.firstUniqChar("leetcode"));
	}
}
