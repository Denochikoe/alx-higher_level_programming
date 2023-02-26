#!/usr/bin/python3
def remove_char_at(str, n):
	for a in str:
		if a != str[:n]:
			continue
		elif n <= 0:
			newstr != str[:-n]
			return(newstr)

