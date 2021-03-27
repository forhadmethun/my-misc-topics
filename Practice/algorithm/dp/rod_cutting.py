"""
l   p
--------------
1 1
2 5
3 8
4 9
5 10
6 17
7 17
8 20

n = 1 => 1
n = 2
    1 + 1 => 2
    2       => 5
{
    cr(2) 
           i = 0
                max(-INF,p[0] +  cr(1))
                                 cr(1) = max(-INF, p[0] + cr[0])
                                         = max(-INF, 1)
                                         = 1
            = max(-INF, p[0] + 1)
            = max(-INF, 2)
            = 2
         i = 1
             max( 2, p[1] + cr(0))
                                 cr(0) = 0
            =max(2, 5)
            = 5
          
}
n=3
    1 + 1 + 1 => 3
    1 + 2 => 6
    2 + 1 => 6
    3 => 8
{
  cr(3)
      i = 0
          max(-INF, p[0]+ cr(2))
                                   cr(2) 
                                       i  = 0
                                            max( -INF, p[0] + cr(1))
                                                                           cr(1) = max(-INF, p[0] +cr[0] )
                                                                                   = 1
                                           = max(-INF, 1 + 1)
                                           =2
                                       i = 1
                                           max( -INF, p[1] + cr(0))
                                           =5
        = max(-INF , 1 + 5)
        =6
    i = 1
       max ( 6 , p[1] + cr(1))
                                    cr(1) = max(-INF ,p[0] + cr(0))
                                            = 1 
       =max(6 ,6)
       = 6
   i = 2
       max( 6, p[2] + cr(0))
       max(6, 8 + 0)
       = 8

    cr(4) == ??? 

}
"""


we'll cut for unit 4
then it can Be, 


revenue of cutting 4(

no cut at all 
1 3 
2 2
3 1
1 1 2
1 2 1
2 1 1
1 1 1 1
)

i) Pn  (understood)
ii) 1 + 1 + 1 + 1 = 4 ( where is this case) (understood)
iii) 2 ^ ( n  - 1 ) (understood) 

s(2)
    2 -> 5 
    1 + 1 -> 2 

r(1) = 1
r(2) = max(5, r(1) +r(1))
     = max( 5, 1 + 1)
     = max( 5, 2)
     = 5

r(3) = max(8, r(1) + r(2), r(2) + r(1) )
     = max(8, r(1) + max(5, r(1) + r(1)),   max(5, r(1) + r(1)) + r(1))
     = max(8, 6, 6)
     = 8 


cut (3)

1 + 1 + 1
1 + 2
2 + 1
3

n = 3
# of ways = 4 
2 ^ ( 3- 1) = 2 ^ 2 = 4


cut (4)
1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
1 + 3
2 + 1 + 1
2 + 2
3 + 1
4
2 ^(4-1) = 2 ^ 3 = 8


 (1<=i<=n)  E i 

 n = 4
 i = 1, 2, 3, 4
1 + 2 + 3 + 4 = 10 
==================================================

n = 0
r(0) = 0

n = 1
r(1) = p(1) + r(1-1)  -> r(0) = 0
     = 1 


n = 2
r(2) = max( p(1) + r(1) , p(2))
     = max ( 1 + 1, 5)
     = 5


1 + 1
2 


n = 3

1 + 1 + 1
1 + 2
2 + 1
3 


r(3) = max(p(1) + r(2), p(2) + r(1), p(3))

r(n-1) + r(n-2) + r (n-3) + ... 


sum 1 <=i <=n   r(n-i)


r(n-1) + r(n-2) + r(n-3)


9 10 3 1 2 6 7

max 
-inf

-100000000 


max = max(-inf, 9)
    = 9 
    
    = max(9, 10)
    = 10

    = max(10,3)
    = 10

    max(10, 1)


    recursion tree 
        cutRod(n)  // ignore price, main point: cut length 

4

4
3 + 1
2 + 2 
1 + 3 

3  = 2 +  1
2 =  1 = 1 

2 -> 1 -> 0
3 -> 2-> 1 -> 0
4 -> 3()

fibonacci: 

dp[] = {0, 1, 1, 2, 3, 5}
fib(5)
            2         +        3
        1 +  1             2 + 1
    1  0                  


[0][1][1][2][][]
fib[0] = 0
fib[1] = 1
fib[2] = fib[1] + fib[0]

fib[n] = fib[n-1] + fib[n-2]

1, 2, 3 , 4,5, 6, 7


1 

2 
    1 + 1
    2 
3 
    1 + 1 + 1
    1 + 2

4 

    1 + D


    dp = [-inf, -inf, -inf, -inf... ]
           1,  5,     8,   10 ,, 





max = -inf
solution
if(current_number > max){
    max = current_number; 
    save the solution!!!
}
max = max (-inf, current_number)