def recurse(expression):
    if len(expression) == 1:
        return expression

    elif len(expression) == 3:
        return [expression[0] + " " + expression[1] + " " + expression[2]]

    else:
        iTimes = -1
        if "X" in expression:
            iTimes = expression.index("X")
        iPlus = -1
        if "+" in expression:
            iPlus = expression.index("+")
        iMinus = -1
        if "-" in expression:
            iMinus = expression.index("-")

        iOperator = -1
        operator = ""
        if iTimes != -1:
            iOperator = iTimes
            operator = "X"
        elif iPlus != -1 and iMinus != -1:
            if iPlus < iMinus:
                iOperator = iPlus
                operator = "+"
            else:
                iOperator = iMinus
                operator = "-"
        elif iPlus != -1:
            iOperator = iPlus
            operator = "+"
        elif iMinus != -1:
            iOperator = iMinus
            operator = "-"

        if operator != "":
            return recurse(
                expression[: iOperator - 1] +
                ["(" + expression[iOperator - 1] + " " + operator + " " + expression[iOperator + 1] + ")"] +
                expression[iOperator + 2 :])
        else:
            return expression


n = int(raw_input())
for i in range(n):
    expression = raw_input().strip().split()
    print recurse(expression)[0]
    print
