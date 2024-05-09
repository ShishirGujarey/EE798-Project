def partition(array, low, high):
 
    pivot = array[high]
 
    i = low - 1
 
    for j in range(low, high):
        if array[j] <= pivot:

            i = i + 1
 
            # Swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])
 
    # Swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])
 
    # Return the position from where partition is done
    return i + 1
     
def quickSort(array, low, high):
    if low < high:

        pi = partition(array, low, high)
 
        # Recursive call on the left of pivot
        quickSort(array, low, pi - 1)
 
        # Recursive call on the right of pivot
        quickSort(array, pi + 1, high)
 
if __name__ == "__main__":
    data = [1, 7, 4, 1, 10, 9, -2]
    print("Unsorted Array 1")
    print(data)
    
    size = len(data)
    
    quickSort(data, 0, size - 1)
    
    print('Sorted Array in Ascending Order:')
    print(data)

    data = [4, 78, 42, 90, 100, -6, 7, 1]
    print("Unsorted Array 2")
    print(data)
    
    size = len(data)
    
    quickSort(data, 0, size - 1)
    
    print('Sorted Array in Ascending Order:')
    print(data)
    