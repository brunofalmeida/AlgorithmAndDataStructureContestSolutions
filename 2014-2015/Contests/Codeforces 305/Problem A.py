def isPalindrome(string):
    for i in range(len(string) / 2):
        if string[i] != string[len(string) - 1 - i]:
            return False

    return True


def main():
    s = raw_input()
    k = int(raw_input())
    if len(s) % k == 0:
        messageLength = len(s) / k
        
        for i in range(k):
            if isPalindrome(s[i * messageLength : (i + 1) * messageLength]) == False:
                print "NO"
                return

        print "YES"
        return
        
    else:
        print "NO"
        return


main()
