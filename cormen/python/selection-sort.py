a = [11, 10, 23, 1000, 44, 3]
b = [5, 4, 3, 2 ,1]
def selectionSort(a):
    print('Before', a)
    for i in range(0, len(a) - 1):
        minIndex = i
        for j in range(i+1, len(a)):
            if(a[j] < a[minIndex]):
                minIndex = j
        if(minIndex != i):
            tempVar = a[i]
            a[i] = a[minIndex]
            a[minIndex] = tempVar
        print('During', a)
    print('After ', a)

selectionSort(a)
