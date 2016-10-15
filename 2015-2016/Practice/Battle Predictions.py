AB, DB = map(int, raw_input().strip().split())
AS, DS = map(int, raw_input().strip().split())

if AB > DS and DB > AS:
    print "Batman"
elif AS > DB and DS > AB:
    print "Superman"
else:
    print "Inconclusive"
