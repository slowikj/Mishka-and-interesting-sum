#!/usr/bin/python3

from functools import reduce

def get_numbers():
	n = int(input())

	return list(map(int,
					input().split(' ')))

def answer_for_query(numbers, query):
	res = 0

	occurences={}
	for i in range(query[0], query[1] + 1):
		if (numbers[i] in occurences):
			occurences[numbers[i]] += 1
		else:
		 	occurences[numbers[i]] = 1

	return reduce((lambda x, y: x ^ y[0]),
				  list(filter((lambda x: x[1] % 2 == 0),
							  occurences.items())),
				  0);

def solve(numbers):
	m = int(input())
	
	for i in range(m):
		beg, end = map(lambda x: int(x) - 1,
					   input().split())

		print(answer_for_query(numbers,
						  	  (beg, end)))


numbers = get_numbers()
solve(numbers)


