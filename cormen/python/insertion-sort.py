a = [5, 2, 4, 6, 1, 3]
b = [31, 41, 59, 26, 41, 58]
c = [31, 41, 59, 26, 41, 58, 33]

def insertionSort(a):
    print('Before sort:', a)
    for j in range(1, len(a)):
        key = a[j]
        #insert a[j] into sorted sequence
        i = j - 1
        #print('j:', j, 'i:', i, 'key:', key)
        while(i >= 0 and a[i] > key):
            a[i + 1] = a[i]
            i = i - 1
        a[i + 1] = key
        print("current state:", a)
    print('After sort:', a)

def ascendingInsertionSort(a):
    print('Before sort:', a)
    for j in range(1, len(a)):
        key = a[j]
        #insert a[j] into sorted sequence
        i = j - 1
        #print('j:', j, 'i:', i, 'key:', key)
        while(i >= 0 and a[i] < key):
            a[i + 1] = a[i]
            i = i - 1
        a[i + 1] = key
        print("current state:", a)
    print('After sort:', a)

def linearSearch(a, v):
    flag = 0
    pos = 0
    for i in range(len(a)):
        if(v == a[i]):
            flag = 1
            pos = i
    if(flag == 1):
        print('value', v, 'is located in position:', pos)
    else:
        print('The value was not found...')

def arrayAddition(a, b):
    c = a.copy()
    if(len(a) > len(b)):
        for i in range(len(b)):
            c[i] = a[i] + b[i]
    elif(len(a) == len(b)):
        for i in range(len(a)):
            c[i] = a[i] + b[i]
    else:
        c = b.copy()
        for i in range(len(a)):
            c[i] = a[i] + b[i]
    print(c)
#Exercises
#2.1 -1
print("Exercies 2.1-1")
insertionSort(b)
print()
#2.1 -2
print("Exercies 2.1-2")
ascendingInsertionSort(b)
print()
#2.1 -3
print("Exercies 2.1-3")
linearSearch(b, 31)
print()
#2.1 -4
print("Exercies 2.1-4")
arrayAddition(a, c)
print()
