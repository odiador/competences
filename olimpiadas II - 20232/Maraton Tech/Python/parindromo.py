def isPalindrome(cad):
    return cad == cad[::-1]

def getPalindromeResult(cad):
    result = "None"
    for i in range(len(cad) - 2):
        for j in range(i + 2, len(cad) + 1):
            sub = cad[i:j]
            if isPalindrome(sub):
                if result == "Odd" and len(sub) % 2 == 0:
                    return "Both"
                elif result == "Even" and len(sub) % 2 == 1:
                    return "Both"
                elif result == "None":
                    if len(sub) % 2 == 0:
                        result = "Even" 
                    else:
                        result = "Odd"
    return result

cad = input()
cad = cad.replace(" ", "")
print(getPalindromeResult(cad))