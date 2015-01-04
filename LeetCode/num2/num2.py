#FileName: num2.py
#Authour: lxw
#Date: 2015-1-4
#Usage: LeetCode num 2.

class Solution:
    def find(self, index):
        pass

    def findAvg(self, index1, index2):
        pass

    # @return a float
    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)
        sum = m + n
        index1 = sum / 2   #odd
        index2 = index1 - 1   #even
        print(A + B)
        if (m + n) % 2 == 0:
            return self.findAvg(index1, index2) #"self." is essential here.
        else:
            return self.find(index1) #"self." is essential here.

def main():
    sol = Solution()
    A = [1, 4, 6, 10]
    B = [2, 3, 20, 22]
    print(sol.findMedianSortedArrays(A, B))
    print("hello world!")

if __name__ == "__main__":
    main()
else:
    print("Imported as a module")

print("hello world!")