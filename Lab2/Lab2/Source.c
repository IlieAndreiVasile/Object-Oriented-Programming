#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>


int prime(int n)
/*
Check if a given natural number is prime.
*/
{
	if (n == 2)
		return 1;

	if (n < 2 || n % 2 == 0)
		return 0;

	for (int i = 3; i*i <= n; i = i + 2)
		if (n % i == 0)
			return 0;
	return 1;
}


void smaller_prime_numbers(int n)
/*
Print all prime numbers smaller than a given natural number.
*/
{
	printf("prime numbers smaller than the given number: ");
	for (int i = n-1; i >= 2; i--)
		if (prime(i))
			printf("%d ", i);
}


void increasing_subsequence()
/*
Read a vector and print the longest increasing contiguous subsequence of the given vector.
*/
{
	int n, v[100], i, length, starting_position, max_length;

	// read the dimension and then the elements of a vector
	printf("Give the dimension of the vector: \n");
	scanf_s("%d", &n);
	printf("Give the elements of the vector: \n");
	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);

	// find the longest increasing contiguous subsequence
	i = starting_position = max_length = 0;
	length = 1;
	while (i < n)
	{
		if (v[i] < v[i + 1])
		{
			length += 1;
		}
		else
		{
			if (length > max_length)
			{
				max_length = length;
				starting_position = i - length + 1;
			}
			length = 1;
		}
		i = i + 1;
	}

	// print the longest increasing contiguous subsequence
	printf("the longest increasing contiguous subsequence: ");
	for (i = starting_position; i < starting_position + max_length; i++)
	{
		printf("%d ", v[i]);
	}
}


void first_prime_numbers(int n)
/*
Generate the first n prime numbers.
*/
{
	printf("the first n prime numbers: ");
	int i = 2;
	int c = 0;
	while (c < n)
	{
		if (prime(i))
		{
			printf("%d  ", i);
			c += 1;
		}
		i += 1;
	}
}


int main()
/*
Print the menu and solve the choosen problem.
*/
{
	printf("\t \t \t \t Menu: \n");
	printf("a. Generate all the prime numbers smaller than a given natural number n. \n");
	printf("b. Given a vector of numbers, find the longest increasing contiguous subsequence. \n");
	printf("c. Generate the first n prime numbers. \n");
	printf("e. exit the program. \n");

	char cmd;
	do
	{	
		printf("Option: \n");
		scanf_s("%c", &cmd);

		if (cmd == 'a')
		{
			printf("Give a number: \n");
			int given_number;
			scanf_s("%d", &given_number);
			smaller_prime_numbers(given_number);
		}
		else if (cmd == 'b')
		{
			increasing_subsequence();
		}
		else if (cmd == 'c')
		{
			printf("Give a number: \n");
			int given_number;
			scanf_s("%d", &given_number);
			first_prime_numbers(given_number);
		}
	} while (cmd != 'e');
	

	system("pause");
	return 0;
}