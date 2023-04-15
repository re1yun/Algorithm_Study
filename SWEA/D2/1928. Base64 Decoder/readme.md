***

base64 decoding을 진행하는 문제이다. 표에 해당되는 부분을 map으로 저장해주고, 문자열에서 받아오는 값들을 6bit으로 변환하여 저장해준다. 4byte를 encoding하여 decoding시에는 3byte로 바꿔야한다. 

num은 4개의 6bit 문자를 포함한다. 

The variable num contains the 24-bit value that represents the 3 decoded characters. Since each base64 character represents 6 bits, num is calculated by shifting each base64 character 6 bits to the left and then adding it to the previous result. This is done for all 4 base64 characters in the group.

Once num is calculated, the next step is to extract the 3 decoded characters from it. This is done using a loop that iterates over each decoded character, starting with the most significant one.

The expression (num >> (j * 8)) shifts num to the right by j * 8 bits, which isolates the j-th decoded character at the current iteration of the loop. For example, if j is 2, then the expression will shift num to the right by 16 bits, which isolates the 8 bits that represent the most significant decoded character.

The expression & 0xff performs a bitwise AND operation with 0xff, which is equivalent to masking the value with the binary number 11111111. This is done to ensure that only the least significant 8 bits of the shifted value are kept, and any other bits are discarded.

Finally, the expression (char) casts the resulting 8-bit value to a character type, which represents the decoded character. This character is then printed to the console using cout.

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV5PR4DKAG0DFAUq&categoryId=AV5PR4DKAG0DFAUq&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=2&pageSize=10&pageIndex=1)
