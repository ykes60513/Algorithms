import math

def binarySearch(x,sortArray):
    low = 0
    high = len(sortArray)-1
    while low <= high:
        mid = math.floor((low + high)/2)
        if x == sortArray[mid]:
            return mid
        elif x < sortArray[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return -1

