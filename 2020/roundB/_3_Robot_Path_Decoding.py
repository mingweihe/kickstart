mod = 10**9
dirs = {'N': (0, -1), 'S': (0, 1), 'W': (-1, 0), 'E': (1, 0)}

# stack solution is simple but coding by cases
def solve(s):
    stack = []
    c_w, c_h = 0, 0
    for c in s:
        if c.isalpha():
            dw, dh = dirs[c]
            c_w += dw
            c_h += dh
        elif c.isdigit():
            stack += (c_w, c_h),
            c_w = c_h = 0
            stack += int(c),
        elif c == '(': continue
        else:
            d = stack.pop()
            c_w *= d
            c_h *= d
            p_w, p_h = stack.pop()
            c_w += p_w
            c_h += p_h
    return 1 + c_w % mod, 1 + c_h % mod


for i in xrange(1, int(raw_input()) + 1):
    s = raw_input()
    w, h = solve(s)
    print 'Case #{}: {} {}'.format(i, w, h)
