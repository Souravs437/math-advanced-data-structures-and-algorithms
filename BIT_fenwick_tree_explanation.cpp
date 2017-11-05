/*
Logic for Point & Range update
=====
NOTE: This is in progress.
=====


> Section 1
___
Point Update
___
i            0  1  2  3  4  5  6  7   8   9
A[i]         0  0  0  0  0  0  0  0   0   0
SumTill[i]   0  0  0  0  0  0  0  0   0   0
___
Now +5 to [3]
___
i            0  1  2  3  4  5  6  7   8   9
A[i]         0  0  0  0 +5  0  0  0   0   0
SumTill[i]   0  0  0  0  5  5  5  5   5   5
___
In Point Update form:
A[3]       += +5
BITarr[3]  += +5 (and, +5 also proprates to other elements, acc to algorithm of BIT)
___
In Point Update form (in general form)
A[i]       += +V
BITarr[i]  += +V (and, +V also proprates to other elements, acc to algorithm of BIT)
___



> Section 2
___
Range Update
___
Assume
___
i                  0  1  2  3  4  5  6  7   8   9
A[i]               0  0  0  0  0  0  0  0   0   0
SumTill[i]         0  0  0  0  0  0  0  0   0   0
___               
Now +5 to [3 to 7]
___               
i                  0  1  2  3  4  5  6  7   8   9
A[i]               0  0  0  5  5  5  5  5   0   0
SumTill[i]         0  0  0  5 10 15 20 25  25  25
___               
Here              
___               
SumTill[i]         0  0  0  5 10 15 20 25  25  25
is                
i                  0  1  2  3  4  5  6  7   8   9
X1[i]             *0  0  0  5  5  5  5  5   0   0
X2[i]             +0  0  0 10 10 10 10 10 -25 -25
.         Where, SumTill[i] = i * X1[i] - X2[i]   --- This will not be used anywhere below, this helps to derive BIT form
___
Here
___
i                  0  1  2        3  4  5  6   7      8   9
X1[i]             *0  0  0        5  5  5  5   5      0   0
X2[i]             +0  0  0       10 10 10 10  10    -25 -25
___
looks like:
___
i                  0  1  2        3  4  5  6   7      8   9
index names                       3            7    7+1
-------------------------------------------------------------
BIT-like-form-X1  *0  0  0       +5  0  0  0   0     -5   0
BIT-like-form-X2  +0  0  0       10  0  0  0   0    -35   0
___

Above in Point Update form: (see above, Section 1)
this is
BITX1[3]   =  +5
BITX1[7+1] =  -5
BITX2[3]   = +10
BITX2[7+1] = -35
So, +5 to [3 to 7] came down to above.
this is range_update(3,7,5).
___

Exact above (in general form) looks like:
___
index              0  1  2        3  4  5  6   7     8   9
index names                       i            j   j+1
-------------------------------------------------------------
BIT-like-form-X1  *0  0  0       +V  0  0  0   0    -V   0
BIT-like-form-X2  +0  0  0  (i-1)*V  0  0  0   0  -j*V   0
___
Above in Point Update form (in general form): (see above, Section 1)
this is
___
(in general form)
BITX1[i]   +=        +V
BITX1[j+1] +=        -V
BITX2[i]   +=  +(i-1)*V
BITX2[j+1] +=      -j*V
So, +V to [i to j] came down to above
this is range_update(i,j,V).
___

*/
