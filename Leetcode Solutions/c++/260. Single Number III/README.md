STEPS

First we run ^(xor) to get the a^b (According to ex 1, 1^1 = 0 and 2^2 = 0 and the final xor = 3^5)
Search the position to do partitioning in binary representation of a^b
Partition the array by this position and get a and b correspondingly
e.g. [1, 2, 1, 3, 2, 5]

1 = 001
2 = 010
1 = 001
3 = 011
2 = 010
5 = 101

After 1st step, we found out that a^b = 3^5 = 6 which is 110
Let's use the righmost setbit to partition our array

Now we create a mask and then find the rightmost setbit so the mask will be, mask = 010

If mask & nums[i] == 0
1 = 001
1 = 001
5 = 101 ✅
1^1^5 => 5

else
2 = 010
2 = 010
3 = 011 ✅
2^2^3 => 3

ans = [3, 5]
