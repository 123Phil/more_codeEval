
d = {}
with open('1input.txt', 'r') as f:
	for line in f:
		parts = line.split()
		letter, code = parts[0], parts[1]
		if letter not in ',/?:@&=+$#':
			print "\t'{}': '{}',".format(code, letter)
