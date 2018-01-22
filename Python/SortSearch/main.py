import random
import sort, search


choose = int(input("Create array by your self or automatically? (1/2)\n"))
while True:
    if choose is not 1 and choose is not 2:
        choose = int(input("Please enter number 1 or 2\n"))
    else:
        break

number = int(input("How many values you wish to insert\n"))
random.seed()
sortArray = list()
if choose == 1:
    sortArray = list(map(int,input("Please insert your array\n").split()))
else:
    for i in range(number):
        sortArray.append(random.randint(1,100))

print(sortArray)
choose = int(input("Please choose the way you want to sort\n1.exchangesort 2.mergesort 3.quicksort\n"))

if choose is 1:
    sort.exchangesort(sortArray)
elif choose is 2:
    sort.mergesort(sortArray)
elif choose is 3:
    sort.quicksort(0,len(sortArray)-1,sortArray)
else:
    print("ERROR")
print(sortArray)

