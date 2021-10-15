def reverse_string(string1):
    rev_str = ""
    for i in range(len(string1)-1, -1, -1):
        rev_str += string1[i]
    return rev_str


string1 = "asustufgaming"
print(reverse_string(string1))
