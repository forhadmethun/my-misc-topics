#hello world
#print("hello forhad");
def fibonacci(n):
    if(n==1):
        return 1
    else:
        return n + fibonacci(n-1)
def merge(left,right,array):
    l = len(left)
    r = len(right)
    i = j = k = 0
    while(i<l and j< r):
        if(left[i] <= right[j]):
            array[k] = left[i]
            i = i + 1
        else:
            array[k] = right[j]
            j = j + 1
        k = k + 1
    while(i<l):
        array[k] = left[i]
        i = i+1
        k = k + 1
    while(j<r):
        array[k] = right[j]
        j = j + 1
        k = k + 1
def merge_sort(array):
    n = len(array)
    if(n<2):
        return
    mid = int(n/2)
    left=[0]* mid
    right=[0] * (n-mid)
    for i in range(0,mid):
        left[i] = array[i]
    for i in range(mid,n):
        right[i-mid] = array[i]
    merge_sort(left)
    merge_sort(right)
    merge(left,right,array)
   # print(n)
    #return 0

# print(fibonacci(10))
my_array = [2,4,1,6,8,5,3,7]
merge_sort(my_array)
for i in my_array:
    print (i,)

# merge_sort([1,2,3])
