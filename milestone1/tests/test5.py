def binary_search(a_list, an_item):
    first = 0
    last = len(a_list) - 1

    while first <= last:
        mid_point = (first + last) // 2
        if a_list[mid_point] == an_item:
            return True, mid_point  # Return True and the index of the found item
        else:
            if an_item < a_list[mid_point]:
                last = mid_point - 1
            else:
                first = mid_point + 1
    return False, -1  # Return False if item is not found

def binary_search_rec(a_list, first, last, an_item):
    if len(a_list) == 0:
        return False, -1
    else:
        mid_point = (first + last) // 2
        if a_list[mid_point] == an_item:
            return True, mid_point
        else:
            if an_item < a_list[mid_point]:
                last = mid_point - 1
                return binary_search_rec(a_list, first, last, an_item)
            else:
                first = mid_point + 1
                return binary_search_rec(a_list, first, last, an_item)

def display_search_results(result, index):
    if result:
        print("Item found at index:", index)
    else:
        print("Item not found")

if __name__ == '__main__':
    a_list = [1, 4, 7, 10, 14, 19, 102, 2575, 10000]
    b_list = [6, 10, 125, 130, 146, 354, 2414, 95465, 715466]
  
    print('Binary Search:', end=" ")
    result, index = binary_search(a_list, 4)
    display_search_results(result, index)

    print('Binary Search:', end=" ")
    result, index = binary_search(b_list, 4)
    display_search_results(result, index)

    print('Binary Search Recursive:', end=" ")
    result, index = binary_search_rec(a_list, 0, len(a_list) - 1, 4)
    display_search_results(result, index)

    print('Binary Search Recursive:', end=" ")
    result, index = binary_search_rec(b_list, 0, len(b_list) - 1, 4)
    display_search_results(result, index)
    