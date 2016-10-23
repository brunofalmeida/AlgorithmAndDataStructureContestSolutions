N = int(raw_input())

eagleList = map(int, raw_input().strip().split())
xyeneList = map(int, raw_input().strip().split())

eagleList.sort()
xyeneList.sort()

eaglePts = 0
xyeneStart = 0
xyeneEnd = len(xyeneList) - 1
for eagleNum in eagleList:
    if eagleNum < xyeneList[xyeneStart]:
        xyeneEnd -= 1

    if eagleNum > xyeneList[xyeneStart]:
        xyeneStart += 1
        eaglePts += 1

print eaglePts


xyenePts = 0
eagleStart = 0
eagleEnd = len(eagleList) - 1
for xyeneNum in xyeneList:
    if xyeneNum < eagleList[eagleStart]:
        eagleEnd -= 1

    if xyeneNum > eagleList[eagleStart]:
        eagleStart += 1
        xyenePts += 1

print xyenePts
