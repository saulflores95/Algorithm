a = [11, 10, 23, 1000, 44, 3]

def merge_sort(A):              #Se define funcion principal
    print('Before:', A)         #Impresion de lista previa a ser sortada
    mergeSort(A, 0, len(A) - 1) #Se manda a llamar funcion. Len -1
    print('After: ', A)

def mergeSort(A, first, last):
    if first < last:
        middle = (first+last) // 2
        mergeSort(A, 0, middle)
        mergeSort(A, middle + 1, last)
        merge(A, first, middle, last)

def merge(A, first, middle, last):
    L = A[first:middle+1]
    R = A[middle+1:last+1]
    L.append(99999999)
    R.append(99999999)
    i = j = 0
    print('Left:', L)
    print('Right', R)
    for k in range(first, last+1):
        if(L[i] <= R[j]):
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j +=1

merge_sort(a)
