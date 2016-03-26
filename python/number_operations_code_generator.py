"""
Author: Phillip Stewart
Date: 25 March 2016
CodeEval Challenge: 190 - Number Operations (helper script)
	I'm using Python to generate brute-force C code.
"""

from itertools import permutations, product


variables = 'abcde'
ops = '+-*'

for V in permutations(variables):
	for O in product(ops, repeat=4):
		print('if ((((({}{}{}){}{}){}{}){}{}) == 42) return 1;'.format(V[0], O[0], V[1], O[1], V[2], O[2], V[3], O[3], V[4]))
