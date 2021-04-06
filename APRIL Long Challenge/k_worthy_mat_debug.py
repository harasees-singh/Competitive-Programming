matrix =    []
#   1 2 3
#   3 4 5
#   5 6 7

# binary search needs to be modified so that it starts from 0 and goes till n*m
copy_matrix = [] #[[1, 2, 3],
              #  [3, 4, 5],
              #  [5, 6, 7]]
#
import copy

def good(i, j, l, m, n, k):
    
    average_of_matrix_of_side_l = -1
    if l>=2:
        if m-i>=l and n-j>=l:
            if i+l-1<=m-1 and j-1>= 0:
                element1 = matrix[i+l-1][j-1]
            else:
                element1 = 0
            if j+l-1<=n-1 and i-1>=0:
                element2 = matrix[i-1][j+l-1]
            else:
                element2 = 0
            if element1 != 0 and element2 != 0:
                average_of_matrix_of_side_l = (matrix[i+l-1][j+l-1] - element2 - element1 + matrix[0][0])/(l**2)
            else:
                average_of_matrix_of_side_l = (matrix[i+l-1][j+l-1] - element2 - element1)/(l**2)
        
    elif l==1:
        if copy_matrix[i][j] >= k:
            return True

    if average_of_matrix_of_side_l >= k:
        return True
    return False
        

def BinarySearch(k, l, m, n):
    mid = 0
    row = mid//n
    column = mid%n
    ans = -1
    if good(0, 0, l, m, n, k):
        ans = BinarySearchOnMatrix(k, l, m, n, mid, mid)
    else:
        mid = 1
        last_mid = 1
        while mid<=n*m-1:
            row = mid//m
            column = mid%m

            if good(row, column, l, m, n, k):
                ans = BinarySearchOnMatrix(k, l, m, n, last_mid, mid)
                break
            else:
                last_mid = mid
                mid = mid*2
    return ans






def BinarySearchOnMatrix(k, l, m, n, left, right):
    
    ans = -1
    mid = 0
    while left<= right and mid <= n*m-1:
        mid = (left+right)//2

        row = mid//m
        column = mid%m

        if good(row, column, l, m, n, k):
            right = mid-1
            ans = mid           # potential answer
        else:
            left = mid+1
    return ans

for _ in range(int(input())):
    n, m, k = map(int, input().split())
    
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    copy_matrix = copy.deepcopy(matrix)
    # creating the prefix sum matrix
    for i in range(n):
        for j in range(1, m):
            matrix[i][j] += matrix[i][j-1]
    # now the matrix has prefix sums along the rows
    for j in range(m):
        for i in range(1, n):
            matrix[i][j] += matrix[i-1][j]
    # prefix sum along columns
    # now every index stores the sum of the elements in the iXj matrix

    count = 0
    # for l in range(1, min(n, m)+1):
    l = 1
    index = BinarySearch(k, l, m, n)
    print(f"index of {l}x{l} squares is ", index)
    if index == -1:
        continue
    else:
        i = index//m
        j = index%m
        if m-i>=l:
            count += max(0, n-l-j+1)
            count += max(0, (m-i-l)*(n-l+1))
    print(count)
    print("good ", good(0, 1, 2, 3, 3, 4))
    print(*matrix)
