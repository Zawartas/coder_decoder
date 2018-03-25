# coder_decoder
A program that codes a text file using a code from CSV, and then decodes it to another file.

So we have a text file called: KP_0005.txt. Also we have a CSV file with codes, that is:
d  00100
e  00101
f  00110
g  00111

...and so on. Iportant notice is that space also has its code.

So we code our text file so it looks like this:
110000000000001010101011011000000000011110111000000101000100000101000000001000001000

What we have to do next is to decode it. We know that the length of code to read has 5 characters. 
So every 5 characters/digits we decode to a given char.
