curtest = 3

was = set()

def test(x, k):
    global curtest
    global was
    f = open("%02d" % curtest, "w")
    print(x, file=f)
    print(k, file=f)
    f.close()
    print(x, k)
    curtest += 1

import random
random.seed("lsnisyimd")


# subtask 1
test(1, 0)
test(7, 0)
test(10, 0)
test(12, 0)
test(100, 0)
test(112, 0)
test(9090, 0)
test(12345, 0)
test(98765, 0)
test(100000, 0)
for i in range(10):
    test(random.randint(1, 100000), 0)

# subtask 2
test(11111111111111111, 0)
test(11111111111111110, 0)
test(11111111111111112, 0)
test(10**17 - 1, 0)
test(10**17 - 10**16, 0)
test(10**17, 0)
for i in range(10):
    test(random.randint(1, 10**17), 0)

# subtask 3
test(1, 1)
test(7, 1)
test(10, 1)
test(12, 1)
test(100, 1)
test(112, 1)
test(9090, 1)
test(12345, 1)
test(98765, 1)
test(100000, 1)
test(55556, 1)
test(55549, 1)
for i in range(8):
    test(random.randint(1, 100000), random.randint(0, 1))

# subtask 4
test(11111111111111111, 1)
test(11111111111111110, 1)
test(11111111111111112, 1)
test(10**17 - 1, 1)
test(10**17 - 10**16, 1)
test(10**17, 1)
for i in range(10):
    test(random.randint(1, 10**17), random.randint(0, 1))

