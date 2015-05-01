/**
 *@FileName: num1_1.java
 *@Author: lxw
 *@Date: Jan 3, 2015
 *@Usage: Use the Built-in Data Structure in Java to solve the problem.
 */
package num1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class num1_1 {
	public static int[] twoSum(int[] numbers, int target) {
		//Hash "numbers" into Map.
		// key = numbers[i], value = [index1, index2,...]
		Map<Integer, ArrayList<Integer>> hashmap = new HashMap<Integer, ArrayList<Integer>>();
		int length = numbers.length;
		for (int i = 0; i < length; ++i) {
			if (hashmap.get(numbers[i]) == null) {
				hashmap.put(numbers[i],
						new ArrayList<Integer>(Arrays.asList(i)));
			} else {
				//NOTE:The following line is OK. get() returns an ArrayList.
				hashmap.get(numbers[i]).add(i);
			}
		}

		//Search in "numbers" with the help of hashMap.
		for (int i = 0; i < length; ++i) {
			int other = target - numbers[i];
			ArrayList<Integer> al = hashmap.get(other);
			if (al != null) {
				int size = al.size();
				int j = 0;
				while (j < size) {
					if (al.get(j) > i) {
						break;
					}
					++j;
				}
				if (j < size) {
					return new int[] { i + 1, al.get(j) + 1 };
				}
			}
		}
		return new int[] { -1, -1 };
	}

	public static void main(String[] args) {
		int[] numbers = new int[9200];
		for (int i = 0; i < 9200; ++i) {
			numbers[i] = 2 * i + 1;
		}
		//int[] numbers = { 0, 3, 4, 0, 0 };
		int[] result = twoSum(numbers, 38);
		System.out.println(result[0] + ", " + result[1]);
	}
}