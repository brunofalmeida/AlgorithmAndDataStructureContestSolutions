N = int(raw_input())

student = []
for i in range(N):
    student.append(raw_input())

correct = []
for i in range(N):
    correct.append(raw_input())

numCorrect = 0
for i in range(N):
    if student[i] == correct[i]:
        numCorrect += 1

print numCorrect
