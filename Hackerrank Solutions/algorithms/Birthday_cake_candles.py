#!/bin/python

import math
import os
import random
import re
import sys

#
# Complete the 'birthdayCakeCandles' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY candles as parameter.
#

def birthdayCakeCandles(arr):
    n= len(arr)
    maxnum = 0
    count = 0
    for i in range(n):
        if arr[i] > maxnum:
            maxnum = arr[i]
            count = 1
        elif arr[i] == maxnum:
            count += 1
    return count        
                  
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    candles_count = int(raw_input().strip())

    candles = map(int, raw_input().rstrip().split())

    result = birthdayCakeCandles(candles)

    fptr.write(str(result) + '\n')

    fptr.close()

