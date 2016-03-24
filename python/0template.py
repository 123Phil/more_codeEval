"""
Author: Phillip Stewart
Date: 18 March 2016
CodeEval Challenge: 
"""

import sys


def main(args):
	if len(args) != 2:
		print 'Usage ~$ ' + args[0] + ' <input file>'
		sys.exit(0)
	else:
		filename = args[1]
	
	with open(filename, 'r') as f:
		for line in f:
			print line


if __name__ == "__main__":
	main(sys.argv)
