from math import log, exp

maxn = 2*10**5+1
logfact = [0] * maxn
yh = [0] * maxn
xw = [0] * maxn

def p(x, y):
    return exp(logfact[x+y-2] - logfact[x-1] - logfact[y-1] - (x+y-2)*log(2))

def solve(w, h, l, u, r, d):
    yh[1] = 0.5 ** (h-1)
    xw[1] = 0.5 ** (w-1)
    for i in xrange(2, w):
        yh[i] = yh[i-1] + 0.5 * p(i, h-1)
    for i in xrange(2, h):
        xw[i] = xw[i-1] + 0.5 * p(w-1, i)

    ans = 0
    x, y = r+1, u-1
    while x <= w and y >= 1:
        if y == 1: ans += 0.5 ** (x-1)
        elif x == w: ans += xw[y]
        else: ans += p(x, y)
        x, y = x + 1, y - 1
    
    x, y = l-1, d+1
    while x >= 1 and y <= h:
        if x == 1: ans += 0.5 ** (y-1)
        elif y == h: ans += yh[x]
        else: ans += p(x, y)
        x, y = x - 1, y + 1
    return ans


for i in xrange(1, maxn):
    logfact[i] = logfact[i-1] + log(i)


for i in xrange(1, int(raw_input())+1):
    w, h, l, u, r, d = map(int, raw_input().split())
    ans = solve(w, h, l, u, r, d)
    print 'Case #{}: {}'.format(i, ans)
