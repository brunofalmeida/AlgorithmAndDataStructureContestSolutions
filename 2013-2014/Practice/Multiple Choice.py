num_questions = input ()

student_answers = []
for x in range (num_questions):
    student_answers.append (raw_input ())

correct_answers = []
for x in range (num_questions):
    correct_answers.append (raw_input ())

correct = 0
for x in range (num_questions):
    if student_answers [x] == correct_answers [x]:
        correct += 1

print correct
