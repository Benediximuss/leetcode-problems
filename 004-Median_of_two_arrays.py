# Finds the median of the sorted combination of two arrays i.e : Array1 = [1,2,3,4]  Array2 = [2,3]  Combination is = [1,2,2,3,3,4] Median is (2 + 3) / 2 = 2.5

def findMedianSortedArrays(nums1, nums2):
    n = []
    for i in nums1:
        n.append(i)
    for i in nums2:
        n.append(i)
    n = sorted(n)
    x = len(n)
    if len(n) % 2 == 0:
        return (n[int(x/2-1)] + n[int(x/2)]) / 2
    else:
        return n[int((x+1)/2-1)]


a = [1, 2, 3, 4]
b = [2, 3]

print(findMedianSortedArrays(a, b))
