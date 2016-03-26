a = [x.strip() for x in "a | b | c | d | e | f | g | h | i | j | k | l | m".split('|')]
b = [x.strip() for x in "u | v | w | x | y | z | n | o | p | q | r | s | t".split('|')]

for l in "mkemhlhsbypm":
	a.append(l)
for l in "trytosolveit":
	b.append(l)

new_a = a + b
b = b + a

d = dict(zip(new_a, b))
for l in 'abcdefghijklmnopqrstuvwxyz':
	if l in d:
		print "\t'{}': '{}',".format(l, d[l])
	else:
		print "NO: ", l
