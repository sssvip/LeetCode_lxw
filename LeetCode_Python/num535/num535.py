#!/usr/bin/python2.7
# FileName: num535.py
# Author: lxw
# Date: 2017-03-18

"""
Num 535: Encode and Decode TinyURL
Source: https://leetcode.com/problems/encode-and-decode-tinyurl/#/description

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Subscribe to see which companies asked this question.

Show Tags
Show Similar Problems
"""

class Codec:
    def __init__(self):
        self.letterDict = {}
        #letterDict = {"0":0, "1":1, ...}
        #for num in xrange(10):
        #    self.letterDict[str(num)] = num

        #letterDict = {"A":11, "B":12, ...}
        for num in xrange(65, 91):
            self.letterDict[chr(num)] = num - 54

        #letterDict = {"a":37, "b":38, ...}
        for num in xrange(97, 123):
            self.letterDict[chr(num)] = num - 60
        self.letterDict['.'] = 61
        self.letterDict['-'] = 62
        self.letterDict['_'] = 63
        self.letterDict['+'] = 64
        self.letterDict['!'] = 65
        self.letterDict['@'] = 66
        self.letterDict['#'] = 67
        self.letterDict['$'] = 68
        self.letterDict['$'] = 68
        self.letterDict['$'] = 68
        self.letterDict['$'] = 68
        self.letterDict['$'] = 68
        self.letterDict['$'] = 68
        print self.letterDict

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        pass

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        pass
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))

if __name__ == '__main__':
    codec = Codec()

