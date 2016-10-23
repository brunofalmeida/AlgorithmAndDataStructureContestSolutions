# My solution:

# Divide the distance travelled into 24 units.
# So, she would travel 12 units/hour in normal traffic, or 6 units/hour in rush hour.

# She only leaves at 0, 20, or 40 minutes past the hour,
# so consider time in intervals of 10 minutes.
# (Initially I tried intervals of 20 minutes, but that didn't work for sample case 2)
# So, she travels at a speed of 2 units/10 minutes in normal traffic, or 1 unit/10 minutes in rush hour.

# To make things simpler, consider time in minutes whenever possible




# Input the time as a string ("HH:MM")
timeInput = raw_input()

# Process the start time
startHours = int(timeInput[0:2])                # convert first 2 characters to an int
startMinutes = int(timeInput[3:5])              # convert last 2 characters to an int


startTime = (startHours * 60) + startMinutes    # in minutes




# Each unit is 1/24 of the total distance she needs to travel
unitsTravelled = 0
currentTime = startTime # in minutes

# While she hasn't reached her destination (travelled 24 units), keep looping
while unitsTravelled < 24:

    # If it is currently rush hour (between 7:00 and 10:00 or between 15:00 and 19:00)
    # (times are converted to minutes for comparison)
    if ( (7 * 60) <= currentTime < (10 * 60) ) or ( (15 * 60) <= currentTime < (19 * 60) ):
        unitsTravelled += 1

    # Otherwise, it is normal traffic
    else:
        unitsTravelled += 2

    # Add an interval of 10 minutes to the current time
    currentTime += 10




# When the loop is done, currentTime will represent the time she arrives at work

# Use integer division to get the whole number of hours
# Modulus the result by 24 (% 24) in case it goes past midnight to the next day
endHours = (currentTime / 60) % 24

# Use modulus division to get the number of minutes
endMinutes = (currentTime % 60)

# The rjust() string function in Python adds characters on the left as padding
# str(endHours).rjust(2, "0") takes endHours and adds "0"s until the result is 2 characters long
# Type help(str.rjust) into the Python Shell for more information

# Print the ending time (add 0s so that hours and minutes are each 2 digits long
print str(endHours).rjust(2, "0") + ":" + str(endMinutes).rjust(2, "0")
