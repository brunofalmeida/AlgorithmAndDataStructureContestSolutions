template = raw_input()
N = int(raw_input())
for i in range(N):
    name = raw_input()
    print template.replace(">", name)
