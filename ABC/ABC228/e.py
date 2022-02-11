from sys import stdin



def modPow(a, n, p):
    if n == 0:
        return 1
    if n == 1:
        return a%p
    if n%2 == 1:
        return (a * modPow(a, n-1, p))%p
    t = modPow(a, n/2, p)
    return (t*t)%p

def modnoPow(a, n):
    if n == 0:
        return 1
    if n == 1:
        return a
    if n%2 == 1:
        return (a * modnoPow(a, n-1))
    t = modnoPow(a, n/2)
    return (t*t)

def main():
    n, k, m = [int(x) for x in stdin.readline().rstrip().split()]
    mod = 998244353
    print(modPow(m, modnoPow(k,n), mod))

if __name__ == '__main__':
    main()
