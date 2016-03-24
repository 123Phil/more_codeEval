"""
Author: Phillip Stewart
Date: 18 March 2016
CodeEval Challenge: 202 - Stepwise Words
"""

import sys


def main(args):
	if len(args) != 2:
		print('Usage ~$ ' + args[0] + ' <input file>')
		sys.exit(0)
	else:
		filename = args[1]
	
	with open(filename, 'r') as f:
		for line in f:
			vals = [int(v) for v in line.strip().split()][1:]
			ave = int(sum(vals) / len(vals))
			total = sum(abs(ave-v) for v in vals)
			ave += 1
			total = min(total, sum(abs(ave-v) for v in vals))
			print(total)


if __name__ == "__main__":
	main(sys.argv)
