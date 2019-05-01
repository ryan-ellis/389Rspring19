#!/usr/bin/env python3

import hashlib
import string

def crack():
	hashes = open("hashes.txt", "r") # open and read hashes.txt
	passwords = open("passwords.txt", "r") # open and read passwords.txt
	characters = string.ascii_lowercase

	hash_set = set()

	for h in hashes:
		input = h.rstrip()
		hash_set.add(input)

	for p in passwords:
		input = p.rstrip()
		for c in characters:
			test_input = c + input
			test_hash = hashlib.sha256(test_input.encode()).hexdigest()
			if test_hash in hash_set:
				print(test_input + ":" + test_hash)
			
if __name__ == "__main__":
	crack()
