#!/bin/bash
:<<eof
#FileName: num195.sh
#Author: lxw
#Date: 20160913

195. Tenth Line

How would you print just the 10th line of a file?

For example, assume that file.txt has the following content:

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
Your script should output the tenth line, which is:
Line 10
[show hint]

Hint:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.
eof

: '
the blank(' ') in the above line is essential.
This is comments.
'
:<<!
This is comments.
!

if false; then
	This is comments.
fi

#head -n 10 file.txt | tail -n 1  #NO: cannot deal with the case that the file contains less than 10 lines
#Method 1: 9ms
tail -n+10 file.txt | head -n 1 #YES: tail -n+10  -> starting with line 10.

#Method 2: 10 ms
sed -n "10p" file.txt

#Method 3: 12 ms
awk 'NR == 10{print $0}' file.txt