roman = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

s = input()

su = 0
def if_add(a,b,c,d):
    if roman[d] > roman[b]:
        return False
    return True

for i in range(0,len(s)-2,2):
    #print(su,i)
    if if_add(s[i],s[i+1],s[i+2],s[i+3]):
        su += int(s[i]) * roman[s[i+1]]
    else:
        su -= int(s[i]) * roman[s[i + 1]]


su+= int(s[-2])* roman[s[-1]]
print(su)

