#Ruby program for inverse() method in Matrix

#Include matrix
require "matrix"

#Initialize a matrix
	mat1 = Matrix[
    [3.2, 5.4, 4.2, 2.2],
		[2.1, 3.2, 3.1, 1.1] ,
		[1.2, 0.4, -0.8, -0.8], 
		[4.7, 10.4, 9.7, 9.7] ]

#prints the inverse matrix
	puts mat1.inverse()

