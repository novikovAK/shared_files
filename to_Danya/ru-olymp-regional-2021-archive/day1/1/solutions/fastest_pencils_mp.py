k = int(input())
a, x = map(int, input().split())
b, y = map(int, input().split())
print(max(
  0,
  (k - a) * x,
  (k - b) * y,
  (k - a) * x + (k - a - b) * y,
  (k - b) * y + (k - a - b) * x
))
