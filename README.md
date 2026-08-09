# Brainfuck Interpreter
This an interpreter/compiler for the brainf**k programming language written in the C language.
## Brainfuck
Brainfuck is a minimal language containing only 8 operators; '+', '-', '*', '/' '>' '<' '\[' '\]', the table below describes, in brief, what these operators do. Everything that you want code should only use these operators, and people have built some weirdly good program using this language.

### Brainfuck Operators
| Operators   | Desciption |
|--------------- | --------------- |
| +   | Increments the Decimal value stored inside the memory block currently being used by 1   |
| -   | Decrements the Decimal value stored inside the memory block currently being used by 1   |
| >   | Selects, for use, the memory block to the right of the memory block currently being used |
| <   | Selects, for use, the memory block to the left of the memory block currently being used |
| .   | Prints the ASCII equivalent to the decimal value stored in the current memory block |
| ,   | Takes a character from the user as input and stores its decimal equivalent to the current memory block |
| \[   | Starts the loop |
| \]   | Runs the body of the loop again if current memory block isn't 0, if it is, then it ends the loop|

I hope the table above gives a little idea of how this language works, but if you want to learn a bit more about this language i'd suggest going through [this blog](https://gist.github.com/roachhd/dce54bec8ba55fb17d3a)


