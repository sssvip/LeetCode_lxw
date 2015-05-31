// Method offered by GCM: from center to two sides. Really fast: 8ms.
class Solution {
	public:
		string longestPalindrome(string s) {
			unsigned long long sLength = s.length();
			if (sLength == 1)
				return s;
			string str = "";
			unsigned long long strLen = 0;
			int maxStart = 0;
			unsigned long long tempStrLen = 0;
			bool flagFront = true;
			bool flagBack = true;
			for (int i = sLength/2-1, m = sLength/2; i >= 0 | m < sLength; --i, ++m) {
				//Front
				if(flagFront){
					if (strLen >= 2*(i+1))
						flagFront = false;
					int subPalLen = 1;
					string subpal = "";
					//s[i]
					int tempStart = 0;
					for(int j = 1; j <= i; ++j) {
						if (s[i-j] == s[i+j]) {
							subPalLen += 2;
							tempStart = i - j;
						}
						else
							break;
					}
					if (subPalLen > strLen) {
						strLen = subPalLen;
						maxStart = tempStart; 
					}
					subPalLen = 0;
					tempStart = 0;
					//s[i] == s[i+1]
					for(int j = 0; j <= i; j++) {
						if (s[i-j] == s[i+1+j]) {
							subPalLen += 2;
							tempStart = i - j;
						}
						else
							break;
					}
					if (subPalLen > strLen) {
						strLen = subPalLen;
						maxStart = tempStart;
					}
				}

				//Back
				if(m < sLength && flagBack){
					if (strLen >= 2*(sLength-m)-1) {
						flagBack = false;
					}
					int subPalLen = 1;
					int tempStart = 0;
					for(int j = 1; j < sLength-m; ++j) {
						if (s[m-j] == s[m+j]) {
							subPalLen += 2;
							tempStart = m - j;
						}
						else
							break;
					}
					if (subPalLen > strLen) {
						strLen = subPalLen;
						maxStart = tempStart;
					}
					subPalLen = 0;
					tempStart = 0;
					for(int j = 0; j < sLength-m-1; j++) {
						if (s[m-j] == s[m+1+j]) {
							subPalLen += 2;
							tempStart = m - j;
						}
						else
							break;
					}
					if (subPalLen > strLen) {
						strLen = subPalLen;
						maxStart = tempStart;
					}
				}
			}
			return s.substr(maxStart, strLen);
		}
};
