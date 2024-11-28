# ord('a') => ordinal : gives the ASCII value
# chr(ASCII_CODE) => gives the letter

import math

arr = [chr(i) for i in range(ord('A'), ord('A')+20)]

# a function that prints an array in binary tree representation... array after array in levels, separated by comma if same level


x = math.ceil(math.log2(8))
print(x, ':', arr[x])
