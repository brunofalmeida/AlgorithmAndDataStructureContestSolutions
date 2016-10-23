N = int(raw_input())
scenes = map(int, raw_input().strip().split())

def recurse():
    global N, scenes

    if scenes.count(0) == 0:
        return True

    else:
        for i, scene in enumerate(scenes):
            if scene == 0:
                for setting in range(1, 5):
                    if (i - 1 >= 0) and (scenes[i - 1] == setting):
                        continue
                    if (i + 1 < N) and (scenes[i + 1] == setting):
                        continue

                    scenes[i] = setting
                    if recurse() == True:
                        return True
                    scenes[i] = 0

        return False


recurse()

print "".join(map(str, scenes))
