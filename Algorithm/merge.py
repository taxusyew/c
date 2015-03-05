#encoding=utf-8

def rightShiftAry(array,i,j):
    _ary = array
    while i < j:
        _ary[j]=_ary[j-1]
        j-=1
    return _ary

def merge(array):
    aryLen = len(array)
    i = 0
    j = aryLen / 2
    pivot = 0

    while j < aryLen:
        if array[i] < array[j]:
            i+=1
        else:
            pivot = array[j]
            array = rightShiftAry(array,i,j)
            array[i]=pivot
            j+=1
            i+=1
    print array

#merge([1,3,5,7,9,2,4,6,8,10])
merge([2,3,5,7,9,1,4,6,8,10])
