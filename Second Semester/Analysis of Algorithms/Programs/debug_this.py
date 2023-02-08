# merge sort. 
def MergeSort(A):
    if len(A) <= 1:
        return A
    mid = len(A) // 2
    left = MergeSort(A[:mid])
    right = MergeSort(A[mid:])
    return Merge(left, right)

def Merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result



list = [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
list.reverse()
print(list)
list = MergeSort(list)
print(list)