/*
Author: Edmund Gunn, Jr.
Exam 2 Q 1-4

Q1. Theorem: For n ≥ 1 , (1 + 2^n) ≤ 3^n.
    Proof By Mathematical induction
    Base Case n = 1
    (1 + 2^1) = 3^1
    3 = 3
    Therefore n = 1, (1 + 2^n) ≤ 3^n
    Inductive step  for any k ≥ 1, (1 + 2^k) ≤ 3^k
    (1 + 2^(k+1)) ≤ 3^(k+1)
    Proving equality starting on left side
    (1 + 2^(k+1))   = 3^k               Algebra 
                    ≤ 3^k+1 * 3^k       inductive hypotheis
                    = (1 + 2^(k)) * 3 
                    ≤ (3 + 6^(k))       1≤k 
                    = (1 + 2^(k+1))     Algebra
    Therefore (1 + 2^(k+1)) ≤ 3^k+1
    


Q2. A) 26 upper case + 26 lower case + 10 digits
    62 possible chracters
    5 slots
    1 must be a digit
    (62*62*62*62*10)
    AllPossible^4*DigitsOnly

    B) |A \(B u C )| = |A| - |B| - |C| + |B n C|
        = C(10,5) - C(8,3) - C(8,3)  + C(8,3)
        = 252- 56 - 56 - 28
        = 168
        |A| = C(10,5) all elements
        |B| = C(8,3) eleminate 3 and 4 as optiions
        |C| = C(8,3) eleminate 3 and 4 as optiions
        |B n C| = C(8,3) intersection of B and C


Q3. A)   I will be addressing Strings with More 1's than 0 As X and All String possible  as Y to represent my probillity answer
        Strings with More 1's than 0  =C(8,1) + C(8,2) + C(8,3) + C(8,4) + C(8,3) + C(8,2)+ C(8,1) + C(8,0)
        All String possible = 2^8
        Probaility of the bit string has more 0s than 1 =(Y-X)/X

    B) x1 = (1,1)
    x2 = (1,2)(2,1)
    x3 = (2,2)(1,3)(3,1)
    x4 = (2,3)(3,2)
    x5 = (3,3)

    |E| = 1*1/36 + 2* 2/36 + 3*3/36 + 4*2/36 + 5*1/36
    |E| = 1/36 + 4/36 + 9/36 + 8/36 + 5/36
    |E| = 27/36

Q4. function1   theta(n)
    using asymptotic analyis , dropping lower order terms, cosntants, and keeping only the most determining factor 
    f(n) = theta(n) n is the most determining factor in this function

    function2   theta(a*n)
    using asymptotic analyis , dropping lower order terms, cosntants, and keeping only the most determining factor 
    f(n) = theta(a*n) a and n are equally as important determining factors in this function
    no other input will inflate or deflate the run time as much as a and n
    theta(a*n)



*/