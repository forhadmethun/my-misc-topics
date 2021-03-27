"""
input: a = [1,3,5], n = 7
output: # of ways to build 7
"""
def solve(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return solve(n-1) + solve(n-3) + solve(n-5)
a = [1,3,5]
print("======================")
print(solve(1))
print(solve(2))
print(solve(3))
print(solve(4))
print(solve(5))
print(solve(6))
print(solve(7))
print("======================\n")

"""
input: 
"""
