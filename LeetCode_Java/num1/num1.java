/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/two-sum/
 */
package num1;

class Solution {
	class HashNode {
		private int value;
		private int index;
		private HashNode next; // NOTE:Here in HashNode, we declare a member
								// whose type is HashNode.

		public HashNode() {
			this.value = -1;
			this.index = -1;
			this.next = null;
		}

		public HashNode(int value, int index, HashNode next) {
			this.value = value;
			this.index = index;
			this.next = next;
		}

		public void setValue(final int value) {
			this.value = value;
		}

		public void setIndex(final int index) {
			this.index = index;
		}

		public void setNext(final HashNode next) {
			this.next = next;
		}

		public int getValue() {
			return this.value;
		}

		public int getIndex() {
			return this.index;
		}

		public HashNode getNext() {
			return this.next;
		}
	}

	// Seperate Chaining
	class Hash {
		// Hash Function: H(x) = x mod SIZE
		private int hashTableSize;
		private HashNode[] hashTable;

		public Hash(final int[] array) {
			int length = array.length;
			// The size of a HashTable must be a prime number.
			this.hashTableSize = nextPrime(length);
			// NOTE: No "Table Head".
			this.hashTable = new HashNode[this.hashTableSize];
			this.hashIntoTable(array);
		}

		// Get the smallest prime number which is bigger than the length of the
		// array.
		private int nextPrime(int num) {
			while (true) {
				boolean flag = true;
				int end = (int) Math.sqrt(num);
				for (int i = 2; i <= end; ++i) {
					if (num % i == 0) {
						flag = false;
						break;
					}
				}
				if (flag)
					return num;
				++num;
			}
		}

		// Hash the array into the table.
		private void hashIntoTable(final int[] array) {
			int length = array.length;
			for (int i = 0; i < length; ++i) {
				// Hash Function. All the following 4 lines are Hash Function.
				int mod = array[i] % this.hashTableSize;
				if (mod < 0) {
					mod += this.hashTableSize;
				}

				/*
				 * //After "new"(without initialization manually), we got an
				 * array filled with "null". if (this.hashTable[mod] == null) {
				 * // First element in the list. HashNode hn = new
				 * HashNode(array[i], i, null); this.hashTable[mod] = hn; } else
				 * { HashNode hn = new HashNode(array[i], i,
				 * this.hashTable[mod].getNext());
				 * this.hashTable[mod].setNext(hn); }
				 */
				// replace the codes in the comment block above with the
				// following 2 lines.
				HashNode hn = new HashNode(array[i], i, this.hashTable[mod]);
				this.hashTable[mod] = hn;
			}
		}

		public int Find(final int target, final int i) {
			// Hash Function. All the following 4 lines are Hash Function.
			int index = target % this.hashTableSize;
			if (index < 0) {
				index += this.hashTableSize;
			}

			HashNode next = this.hashTable[index];
			while (next != null) {
				if (next.getValue() == target) {
					int temp = next.getIndex();
					if (temp != i) { // "temp == i" means same element, so we
										// need to continue searching.
						break;
					}
				}
				next = next.getNext();
			}
			if (next == null) { // No
				return -1;
			} else { // Yes
				return next.getIndex();
			}
		}
	}

	/* * //This method is much too slow. O(n) public static int inArray(int
	 * element, int[] numbers, int start) { int length = numbers.length; if
	 * (start >= length) { return -1; } for (int i = start; i < length; ++i) {
	 * if (element == numbers[i]) { return i; } } return -1; }
	 */

	public int[] twoSum(final int[] numbers, final int target) {
		Hash hash = new Hash(numbers);
		int[] result = { -1, -1 };
		int length = numbers.length;
		for (int i = 0; i < length; ++i) {
			// Much too slow: O(n)
			// int res = inArray(target-numbers[i], numbers, i+1);
			// Much faster: O(1)
			int res = hash.Find(target - numbers[i], i);
			if (res != -1) {
				result[0] = i + 1;
				result[1] = res + 1;
				break;
			}
		}
		return result;
	}

}

public class num1 {
	public static void main(String[] args) {
		int[] numbers = {2, 7, 3, 3};
		/*
		int[] numbers = new int[9200];
		for (int i = 0; i < 9200; ++i) {
			numbers[i] = i;
		}
		*/

		Solution sl = new Solution();
		int[] result = sl.twoSum(numbers, 5);
		System.out.format("result[0]=%d, result[1]=%d\n", result[0], result[1]);
	}
}