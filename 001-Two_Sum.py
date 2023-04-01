# finds two indexes in an array that array[i1] + array[i2] gives target number

def twoSum(nums, target):
    k = 0
    idx = []

    for i in range(len(nums)):

        if k == 1:
            break

        else:
            for ii in range(len(nums)):
                if k == 0:
                    if ii != i:

                        if nums[i]+nums[ii] == target:
                            idx.append(i)
                            idx.append(ii)
                            k = 1
                else:
                    break

    return sorted(idx)


print(twoSum([2, 7, 11, 15], 9))
