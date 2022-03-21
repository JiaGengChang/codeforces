# test case generator

from numpy import random


if __name__ == "__main__":
    t=1000
    mxn=200
    lo=-1000
    hi=1000
    fn="input.txt"

    with open(fn, 'w') as f:
        print(t,file=f);
        for i in range(t):
            n = random.randint(mxn-1)+1
            print(n,file=f)
            x = [_+lo for _ in random.randint(hi-lo,size=(n))]
            for xx in x:
                f.write(str(xx))
                f.write(' ')
            f.write('\n')
