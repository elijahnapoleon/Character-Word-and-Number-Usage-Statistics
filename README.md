# Character-Word-and-Number-Usage-Statistics

Objectives: Practice selecting and making use of appropriate STL containers and algorithms to perform tasks.

Statement of Work: Implement a program that collects the statistics of word, number, and character usage in a file (redirected as the standard input). 

Requirements:

Write a program that will read input (from standard input) until end of input is reached ("end of file"), which will count the number of times each word, number, and character appears in the input.

A word is defined as a consecutive sequence of letters ('a'..'z' or 'A'..'Z').

Words are case insensitive ("AA", "Aa", "aA", and "aa" are the same).

A number is defined as any consecutive sequence of digits ('0'..'9').

Note that both words and numbers can be of length of 1, that is, contain one letter or one digit, respectively.

Different sequences represent different numbers. For example, number "001" is different from number "1".

Words are separated by any non-letter characters.

Numbers are separated by any non-digit characters.

Output specifications:
Your program should track the number of times each word, number, and character appears.

The program should then output the ten most used characters, the ten most used numbers, and the ten most used words, along with the number of times each of these characters/numbers/words are used.

Since words are case insensitive, the program should only output the words in lower case.

The characters, numbers and words should be printed in descending order based on the number of times they are used.
