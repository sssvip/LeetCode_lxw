#!/usr/bin/python3
# FileName: num535.py
# Author: lxw
# Date: 2017-04-28

"""
Num 535: Encode and Decode TinyURL
Source: https://leetcode.com/problems/encode-and-decode-tinyurl/#/description

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl
and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode
algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
decoded to the original URL.
"""

import random
import string


class Codec1:
    """
    Accepted, but meaningless.
    Time: O(n). 75 ms
    """
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl:
            urlLetterList = list(longUrl)
            longUrl = "".join([chr(ord(letter)+1) for letter in urlLetterList])
        return longUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        if shortUrl:
            urlLetterList = list(shortUrl)
            shortUrl = "".join([chr(ord(letter)-1) for letter in urlLetterList])
        return shortUrl


# References: https://discuss.leetcode.com/topic/81637/two-solutions-and-thoughts
class Codec2:
    """
    OK
    But could the same longUrl be encoded as the same shortUrl?(This may be useful when an attacker requests the same url for a lot of times)
    The answer is "No" for this method.
    """

    alphabet = string.ascii_letters + string.digits

    def __init__(self):
        self.code_url = {}

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        while 1:
            shortUrl = "".join([random.choice(Codec.alphabet) for _ in range(6)])
            if shortUrl not in self.code_url:
                self.code_url[shortUrl] = longUrl
                break
        return "http://xiaoweiliu.cn/" + shortUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.code_url[shortUrl[-6:]]


# References: https://discuss.leetcode.com/topic/81637/two-solutions-and-thoughts
class Codec:
    """
    Better
    Time: O(1). 58 ms
    Space: O(n)
    The same longUrl would be encoded as the same shortUrl.
    """
    _long_short = {}
    _short_long = {}
    alphabet = string.ascii_letters + string.digits
    
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        if longUrl in self._long_short:
            return self._long_short[longUrl]
        else:
            while 1:
                short_url = "".join([random.choice(self.alphabet) for _ in range(6)])
                if short_url not in self._short_long:
                    self._long_short[longUrl] = short_url
                    self._short_long[short_url] = longUrl
                    break
            return "http://tinyurl.com/" + short_url

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        short_url = shortUrl[-6:]
        if short_url in self._short_long:
            return self._short_long[short_url]
        else:
            return shortUrl

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))


if __name__ == '__main__':

    # Your Codec object will be instantiated and called as such:
    # codec = Codec()
    # codec.decode(codec.encode(url))

    codec = Codec()
    encodeResult = codec.encode("https://www.baidu.com")
    print("encode:", encodeResult)
    decodeResult = codec.decode(encodeResult)
    print("decode:", decodeResult)
    print("------" * 20)
    encodeResult = codec.encode("https://www.baidu.com")
    print("encode:", encodeResult)
    decodeResult = codec.decode(encodeResult)
    print("decode:", decodeResult)
    print("------" * 20)
    encodeResult = codec.encode("https://www.baidu.com")
    print("encode:", encodeResult)
    decodeResult = codec.decode(encodeResult)
    print("decode:", decodeResult)
    print(codec.code_url)
