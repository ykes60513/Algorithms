import math

def exchangesort(sortArray):
    n = len(sortArray)
    for i in range(n):
        for j in range(n):
            if (sortArray[i] < sortArray[j]):
                temp = sortArray[i]
                sortArray[i] = sortArray[j]
                sortArray[j] = temp


def mergesort(sortArray):
    if len(sortArray) > 1 :
        h = len(sortArray)//2
        U = sortArray[:h]
        V = sortArray[h:]
        mergesort(U)
        mergesort(V)

        i = 0
        j = 0
        k = 0
        while i < len(U) and j < len(V):
            if U[i] < V[j]:
                sortArray[k] = U[i]
                i += 1
            else:
                sortArray[k] = V[j]
                j += 1
            k += 1
        while i < len(U):
            sortArray[k] = U[i]
            i += 1
            k += 1
        while j < len(V):
            sortArray[k] = V[j]
            j += 1
            k += 1

def partition(low,high,sortArray):
    pivotitem = sortArray[low]
    j = low
    for i in range(low + 1,high+1):
        if sortArray[i] < pivotitem:
            j += 1
            sortArray[i],sortArray[j] = sortArray[j],sortArray[i]

    sortArray[low],sortArray[j] = sortArray[j],sortArray[low]
    return j


def quicksort(low,high,sortArray):
    if high > low:
        pivotpoint = partition(low,high,sortArray)
        quicksort(low,pivotpoint-1,sortArray)
        quicksort(pivotpoint+1,high,sortArray)


