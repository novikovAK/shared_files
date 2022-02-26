curtest = 2

was = set()

def test(d, m, w, i, j, k):
    global curtest
    global was
    f = open("%02d" % curtest, "w")
    print(d, m, w, file=f)
    print(i, j, k, file=f)
    was.add((d, m, w, i, j, k))
    f.close()
    print(d, m, w, ' ', i, j, k)
    curtest += 1

import random
random.seed("lsnisyimd")


# subtask 1
test(1, 1, 1, 1, 1, 1)
test(1, 1, 1, 1, 1, 2)
test(1, 1, 1, 1, 1, 1000000000)
test(1, 1, 2, 1, 1, 1)
test(1, 1, 2, 1, 1, 2)
test(1, 1, 26, 1, 1, 1)
test(1, 1, 26, 1, 1, 2)
test(1, 1, 26, 1, 1, 26)
test(1, 1, 26, 1, 1, 27)
test(1, 1, 26, 1, 1, 1000000000)

# subtask 2
test(2, 1, 1, 1, 1, 1)
test(2, 1, 1, 1, 1, 2)
test(2, 1, 1, 1, 1, 10000000)
test(2, 1, 1, 2, 1, 1)
test(2, 1, 1, 2, 1, 2)

test(2, 1, 1, 2, 1, 10000000)
test(2, 1, 2, 1, 1, 1)
test(2, 1, 2, 1, 1, 2)
test(2, 1, 2, 2, 1, 1)
test(2, 1, 2, 2, 1, 2)

test(10, 1, 26, 1, 1, 1)
test(10, 1, 26, 1, 1, 2)
test(10, 1, 26, 1, 1, 26)
test(10, 1, 26, 1, 1, 27)
test(10, 1, 26, 10, 1, 1)

test(10, 1, 26, 10, 1, 2)
test(10, 1, 26, 10, 1, 26)
test(10, 1, 26, 10, 1, 27)
test(100, 1, 26, 10, 1, 1)
test(100, 1, 26, 10, 1, 2)

test(100, 1, 26, 10, 1, 26)
test(100, 1, 26, 10, 1, 27)
test(100, 1, 26, 10, 1, 10000000)

for i in range(7):
    d = random.randint(1, 100)
    test(d, 1, random.randint(1, 26), random.randint(1, d), 1, random.randint(1, 10**7))

# subtask 3

test(100, 1, 26, 1, 1, 10**9)
test(1, 100, 26, 1, 1, 10**9)
test(100, 100, 26, 1, 1, 10**9)

for i in range(7):
    d = random.randint(1, 100)
    m = random.randint(1, 100)
    test(d, m, random.randint(1, 26), 1, 1, random.randint(1, 10**9))

# subtask 4


test(100, 1, 26, 100, 1, 1)
test(1, 100, 26, 1, 100, 1)
test(100, 100, 26, 100, 100, 1)

for i in range(7):
    d = random.randint(1, 100)
    m = random.randint(1, 100)
    test(d, m, random.randint(1, 26), random.randint(1, d), random.randint(1, m), 1)

# subtask 5

test(100, 1, 26, 100, 1, 100)
test(1, 100, 26, 1, 100, 100)
test(100, 100, 26, 100, 100, 100)

for i in range(7):
    d = random.randint(1, 100)
    m = random.randint(1, 100)
    test(d, m, random.randint(1, 26), random.randint(1, d), random.randint(1, m), random.randint(1, 100))

# subtask 6

test(100, 1, 26, 100, 1, 10**9)
test(1, 100, 26, 1, 100, 10**9)
test(100, 100, 26, 100, 100, 10**9)

for i in range(17):
    d = random.randint(1, 100)
    m = random.randint(1, 100)
    test(d, m, random.randint(1, 26), random.randint(1, d), random.randint(1, m), random.randint(1, 10**9))

