import math
import random
import time
import numpy
from pandas import DataFrame

# BubbleSort


def BubbleSort(numList):
    for i in range(len(numList)-1, 0, -1):
        for j in range(0, i):
            if numList[j] > numList[j+1]:
                numList[j], numList[j + 1] = numList[j+1], numList[j]

# InsertionSort


def InsertionSort(numList):
    for i in range(1, len(numList)):
        for j in range(i, 0, -1):
            if numList[j-1] > numList[j]:
                numList[j-1], numList[j] = numList[j], numList[j-1]

# Merge Sort에서 나뉘어진 두 리스트를 합치는 함수


def MergeAlgo(leftList, rightList):
    temp = []
    while leftList or rightList:
        if leftList and rightList:
            if leftList[0] < rightList[0]:
                temp.append(leftList.pop(0))
            else:
                temp.append(rightList.pop(0))
        elif leftList and not rightList:
            temp.append(leftList.pop(0))
        elif rightList and not leftList:
            temp.append(rightList.pop(0))
    return temp

# Merge Sort


def MergeSort(numList):
    if len(numList) <= 1:
        return numList
    mid = len(numList)//2
    left = numList[:mid]
    right = numList[mid:]
    left = MergeSort(left)
    right = MergeSort(right)
    return MergeAlgo(left, right)


# Quick Sort


def QuickSort(numList):
    if len(numList) <= 1:
        return numList
    left = []
    right = []
    pivotIdx = len(numList)//2
    pivot = numList[pivotIdx]

    for i in range(0, pivotIdx):
        if pivot < numList[i]:
            right.append(numList[i])
        else:
            left.append(numList[i])
    for i in range(pivotIdx+1, len(numList)):
        if pivot < numList[i]:
            right.append(numList[i])
        else:
            left.append(numList[i])
    return QuickSort(left) + [pivot] + QuickSort(right)


# Radix Sort를 구현하기 위해 만든 Counting Sort
# RadixSort에서 받은 numberList들과 정렬해야하는 자리수를 받아 소팅해줍니다


def CountingSort(numList, exp, base):
    size = len(numList)
    output = [0]*size
    count = [0]*base
    for i in range(size):
        count[(numList[i]//exp) % base] += 1
    for i in range(1, base):
        count[i] += count[i-1]
    for i in range(size-1, -1, -1):
        idx = numList[i]//exp
        output[count[idx % base]-1] = numList[i]
        count[idx % base] -= 1
    for i in range(size):
        numList[i] = output[i]

# Radix Sort
# CountingSort를 이용해 1의 자리수부터 numList의 가장큰 수의 자리수까지
# CountingSort를 순사적으로 실행합니다


def RadixSort(numList, base=10):
    maxval = max(numList)
    exp = 1
    while exp <= maxval:
        CountingSort(numList, exp, base)
        exp *= base

# Bucket Sort
# inputSize는 100,1000,10000으로 정해져 있습니다
# 따라서 numList의 크기를 가지고 만들어야할 slot의 갯수를 정해줍니다
# inputSize를 numOfSlot으로 나눠서 나온 값을 모든 숫자에 나눕니다(이때 꼭 int변환이나 //연산자 사용해야합니다)
# 그리고 해당 값에 해당하는 bucket idx에 들어가서 값을 저장합니다
# 각 bucket당 소팅을 해주고 모든 bucket을 합쳐서 return해줍니다


def BucketSort(numList, numOfSlot=10):
    # bucket number 10, 20, 50 for 100, 1000, 10000
    # 초기화
    inputSize = len(numList)
    # 만약 inputSize의 크기가 100이면 numOfSlot을 10, 1000이면 20, 10000이면 50으로 만듭니다
    if inputSize == 1000:
        numOfSlot = 20
    if inputSize == 10000:
        numOfSlot = 50
    # 값을 범위에 따라 나눠주는 modular변수를 만듭니다
    modular = inputSize//numOfSlot
    # 버킷들 초기화
    buckets = [[] for i in range(numOfSlot+1)]
    # 범위에 따라 버킷에 담습니다
    for i in range(0, len(numList)):
        buckets[numList[i]//modular].append(numList[i])
    # 각 버킷들을 순회하면서 정렬합니다(이때 stable sort로 quick sort를 적용했습니다)
    # 정렬한 리스트를 integList에 모아줍니다
    integList = []
    for bucket in buckets:
        integList.extend(QuickSort(bucket))
    return integList


def isCorrectlySorted(sortedNumLists):
    correctlySortedNumList = sortedNumLists[0]
    for idx in range(1, len(sortedNumLists)):
        if sortedNumLists[idx] != correctlySortedNumList:
            if idx == 1:
                print("Insertion sort have problem")
            elif idx == 2:
                print("Merge sort have problem")
            elif idx == 3:
                print("Quick sort have problem")
            elif idx == 4:
                print("Radix sort have problem")
            elif idx == 5:
                print("Bucket sort have problem")
            return False
        return True


source = [[] for i in range(6)]

for idx, numOfInputs in enumerate([100, 1000, 10000]):
    numList = []
    sortedNumLists = []
    for i in range(numOfInputs, 0, -1):
        numList.append(i)
    # for i in range(numOfInputs):
    #     numList.append(math.ceil(random.random()*numOfInputs))
    # print("Input list is")
    # print(numList)

    tempList = numList[:]
    print("Running Bubble Sort")
    start = time.time()
    BubbleSort(tempList)
    end = time.time() - start
    source[0].append(end)
    sortedNumLists.append(tempList)

    tempList = numList[:]
    print("Running Insertion Sort")
    start = time.time()
    InsertionSort(tempList)
    end = time.time() - start
    source[1].append(end)
    sortedNumLists.append(tempList)

    tempList = numList[:]
    print("Running Merge Sort")
    start = time.time()
    tempList = MergeSort(tempList)
    end = time.time() - start
    source[2].append(end)
    sortedNumLists.append(tempList)

    tempList = numList[:]
    print("Running Quick Sort")
    start = time.time()
    tempList = QuickSort(tempList)
    end = time.time() - start
    source[3].append(end)
    sortedNumLists.append(tempList)

    tempList = numList[:]
    print("Running Radix Sort")
    start = time.time()
    RadixSort(tempList)
    end = time.time() - start
    source[4].append(end)
    sortedNumLists.append(tempList)

    tempList = numList[:]
    print("Running Bucket Sort")
    start = time.time()
    tempList = BucketSort(tempList)
    end = time.time() - start
    source[5].append(end)
    sortedNumLists.append(tempList)

    print("Correctness Checking..")
    correctnessCheck = isCorrectlySorted(sortedNumLists)
    print("for input size ", numOfInputs)
    if correctnessCheck == False:
        print("Code it again")
    else:
        print("Correctly worked")


df = DataFrame(source, columns=['n=100 ', 'n=1000 ', 'n=10000 '], index=[
    'Bubble', 'Insertion', 'Merge', 'Quick', 'Radix', 'Bucket'])
print(df)
