
def find_max(arr):
    arr.sort()
    return arr[-1]


# Iterating through all the elements in the list and comparing each element
def find_max(arr):
    max_element = arr[0]
    for i in range(1, len(arr)):
        if arr[i] > max_element:
            max_element = arr[i]
    return max_element


# Using the in-built max() function
def find_max(arr):
    return max(arr)
