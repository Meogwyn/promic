Usage: `./main <output file name>`

Creates a file in the working directory, takes a 'maximum' number and generates
promic numbers using consecutive non-negative whole numbers up to the 
'maximum' number as the basis for each number. Except these aren't really 
promic numbers, seeing as the formula is `n ^ 2 * (n ^ 2 + 1)` rather than
`n * (n + 1)`.

The author is aware of the extreme banality of this software and questions why
he made it in the first place. Probably to test the GMP library.
