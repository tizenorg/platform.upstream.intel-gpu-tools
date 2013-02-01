#!/usr/bin/env python3

import argparse
import os
import sys
import ast
import subprocess

def parse_file(file):
	for line in file:
		register = ast.literal_eval(line)
		value = subprocess.check_output(["../intel_reg_read", register[1]])
		value = value.decode('UTF-8') # convert the byte array to string
		value = value.rstrip() #dump the newline
		value = value.split(':') #output is 'addr : offset'
		print(value[0], "(", register[0], ")", value[1])


parser = argparse.ArgumentParser(description='Dumb register dumper.')
parser.add_argument('-b', '--baseless', action='store_true', default=False, help='baseless mode, ignore files starting with base_')
parser.add_argument('profile', nargs='?', type=argparse.FileType('r'), default=None)
args = parser.parse_args()

#parse anything named base_ these are assumed to apply for all gens.
if args.baseless == False:
	for root, dirs, files in os.walk('.'):
		for name in files:
			if name.startswith(("base_")):
				file = open(name.rstrip(), 'r')
				parse_file(file)

if args.profile == None:
	sys.exit()

for extra in args.profile:
	extra_file = open(extra.rstrip(), 'r')
	parse_file(extra_file)