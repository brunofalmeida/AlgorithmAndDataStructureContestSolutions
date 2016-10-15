Va, Vb, M = map(int, raw_input().strip().split())

def recurse(aOld, bOld, stepsOld):
    if aOld == M or bOld == M:
        return stepsOld

    stepsLists = []
