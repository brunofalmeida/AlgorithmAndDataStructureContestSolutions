weight = float (raw_input ())
height = float (raw_input ())
BMI = weight / height **2

if BMI < 18.5:
    print "Underweight"
elif BMI <= 25:
    print "Normal weight"
else:
    print "Overweight"
