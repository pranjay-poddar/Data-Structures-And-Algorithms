"""
Add Minimum Characters
This Problem was asked in Geeksforgeeks Interview Series Samsung
Problem - Given an string `str`, find the minimum characters to be added to front of the string to make it a palindrome.

Idea -
1. LPS Array of KMP Algorithm is used - https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
2. We concat string by concatenating given string, a special character and reverse of given string then we will get lps array for this concatenated string.
3. Minimum number of character needed to make the string a palindrome is length of the input string minus last entry of our lps array.

Test cases -
1.  I/P - AACECAAAA
    O/P - 2
2.  I/P - ABA
    O/P - 0
3.  I/P - AB
    O/P - 1
4.  I/P - CAACC
    O/P - 1

Time Complexity - O(n)
"""


def computeLPSArray(string):
    M = len(string)
    lps = [None] * M

    length = 0
    lps[0] = 0

    i = 1
    while i < M:
        if string[i] == string[length]:
            length += 1
            lps[i] = length
            i += 1

        else:
            if length != 0:
                length = lps[length - 1]

            else:
                lps[i] = 0
                i += 1

    return lps

# Below method returns minimum character to be added at front to make string palindrome


def getMinCharToAddedToMakeStringPalin(string):
    revStr = string[::-1]
    concat = string + "$" + revStr

    lps = computeLPSArray(concat)

    return len(string) - lps[-1]

s = input()
print(getMinCharToAddedToMakeStringPalin(s))
