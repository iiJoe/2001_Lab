import random

S = 50
comparisons = 0

def insertionSort(arr):
    global comparisons
    length = len(arr);
    for i in range(1, length):
        for j in range(i, 0, -1):
            comparisons += 1
            if arr[j - 1] > arr[j]:
                tmp = arr[j - 1]
                arr[j - 1] = arr[j]
                arr[j] = tmp
            else:
                break

def merge(left, right):
    sorted = [];

    leftIndex = 0;
    rightIndex = 0;
    global comparisons

    while (leftIndex < len(left) or rightIndex < len(right)):
        if leftIndex == len(left):
            sorted.append(right[rightIndex]);
            rightIndex += 1
        elif rightIndex == len(right):
            sorted.append(left[leftIndex])
            leftIndex += 1
        elif (left[leftIndex] < right[rightIndex]):
            sorted.append(left[leftIndex])
            leftIndex += 1
            comparisons += 1
        else:
            sorted.append(right[rightIndex]);
            rightIndex += 1
            comparisons += 1
    return sorted;

def mergeSort(arr):
    length = len(arr)
    if length <= S:
        insertionSort(arr)
        return arr

    else:
        if len(arr) == 1:
            return arr
        # split array into 2
        mid = (int) (length // 2)

        #merge sort left and right
        l = arr[:mid]
        r = arr[mid:]
        left = mergeSort(l)
        right = mergeSort(r)

        # merge sorted arrays together
        return merge(left, right)


def main():
    size = 1000
    global comparisons

    while size <= 10000000:
        comparisons = 0
        arr = random.sample(range(1, size + 1), size)
        sorted = mergeSort(arr)
        print("Size: ", size, " Comparisons: ", comparisons)
        size *= 10

main()
