"""
Author: Phillip Stewart
Date: 18 March 2016
CodeEval Challenge: Sample Frequency!
	This is a 'Hard' challenge...
	but not to fear, I have some experience with musical note recognition!
"""

import sys
import numpy as np

# import matplotlib.pyplot as plt

# def plot(v):
# 	plt.plot(v, 'ro')
# 	plt.show()


def normalize(v):
	# Normalize slope and offset around ~0
	begin = np.mean(v[:500])
	end = np.mean(v[-500:])
	v = np.subtract(v, np.arange(begin, end, (end-begin)/2010.0)[:2000])
	begin = np.mean(v[:200])
	end = np.mean(v[-200:])
	v = np.subtract(v, np.arange(begin, end, (end-begin)/2010.0)[:2000])
	# Normalize amplitude to ~100
	begin = 50.0 / np.mean(np.fabs(v[:200]))
	end = 50.0 / np.mean(np.fabs(v[-200:]))
	v = np.multiply(v, np.arange(begin, end, (end-begin)/2010.0)[:2000])
	return v


def smooth(v):
	""" Points are averaged with their neighbors,
	first even points, then odd points.
	"""
	for _ in range(2):
		for i in xrange(0, len(v)-2, 2):
				v[i+1] = (v[i] + v[i+1] + v[i+2]) / 3
		for i in xrange(1, len(v)-3, 2):
				v[i+1] = (v[i] + v[i+1] + v[i+2]) / 3
	return v



# def remove_outliers(v):
# 	"""removes anything outside one standard dev."""
# 	mean = np.mean(v)
# 	dev = np.std(v)
# 	return v[np.fabs(v - mean) < dev]


# def get_runs(v):
# 	pos = np.signbit(v)
# 	runs = []
# 	prev = True
# 	run_len = 0
# 	for x in np.nditer(pos):
# 		if prev == x:
# 			run_len += 1
# 		else:
# 			prev = not prev
# 			if run_len != 0:
# 				runs.append(run_len)
# 			run_len = 0
# 	return len(runs), np.mean(np.sort(np.asarray(runs))[2:-2])


def count_runs(v):
	pos = np.signbit(v)
	runs = 0
	prev = pos[0]
	for x in np.nditer(pos):
		if prev != x:
			prev = not prev # =x
			runs += 1
	return runs


def hone(freq, v):
	#check range of freqs with windows
	freq -= freq % 10
	freqs = range(freq-30, freq+60, 10)
	least = None
	corr = 0
	for fr in freqs:
		wave_len = 2000.0 / fr
		total = 0
		for i in range(100):
			total += np.fabs(v[i] - v[i+int(wave_len)])
			total += np.fabs(v[i] - v[i+int(wave_len*2)])
		if least is None or total < least:
			least = total
			freq = fr
	return freq


def main(args):
	if len(args) != 2:
		print 'Usage ~$ ' + args[0] + ' <input file>'
		sys.exit(0)
	else:
		filename = args[1]
	
	with open(filename, 'r') as f:
		for line in f:
			vals = np.asarray([int(x) for x in line.strip().split()])
			vals = normalize(vals)
			#vals = smooth(vals)
			#plot(vals)
			#num_runs, run_len = get_runs(vals)
			num_runs = count_runs(vals)
			freq = 5 * num_runs
			if freq % 10 == 5:
				freq += 5
			freq = hone(freq, vals)
			print freq


if __name__ == "__main__":
	main(sys.argv)
