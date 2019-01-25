import itertools

def judgePoint24(nums):
    def f(s1, s2):
        res = []
        for a in s1:
            for b in s2:
                res.append('(' + a + '+' + b + ')')
                res.append('(' + a + '-' + b + ')')
                res.append('(' + b + '-' + a + ')')
                res.append(a + '*' + b)
                res.append(a + '/' + b)
                res.append(b + '/' + a)
        return res

    nums = [str(float(i)) for i in nums]
    maxi = -1
    for c in itertools.permutations(nums):
        eq1 = f(f(f([c[0]], [c[1]]), [c[2]]), [c[3]])
        eq2 = f(f([c[0]], [c[1]]), f([c[2]], [c[3]]))
        for eq in eq1 + eq2:
            try:
                k = eval(eq)
                #print(k)
                if k == 24:
                    print(24)
                    return
                if k <= 24.1 and k == int(k):
                    maxi = max(maxi,int(k))
                    #print (eq.replace(".0", ""))
                    #return True
            except:
                pass
    print(maxi)
    #return False


for _ in range(int(input())):
    fin = 0
    k = [0]*4
    k[0] = int(input())
    k[1] = int(input())
    k[2] = int(input())
    k[3] = int(input())
    judgePoint24(k)