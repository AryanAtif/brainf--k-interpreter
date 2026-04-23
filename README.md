# Brainfuck Interpreter
This an interpreter/compiler for the brainf**k programming language written in the C language. Im gonna admit its poorly written, but it is what it is. 

## A wee bit of Brainfuck
Brainfuck is a minimal language containing only 8 operators; '+' '-' '>' '<' '\[' '\]', the table below describes, in brief, what these operators do. Everything that you want code should only use these operators, and people have built some weirdly good program using this language.

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

## Build the program

### Get a Compiler
#### For Linux and MacOS

- Verify if you have a C compiler installed by running `gcc --version` (you may replace "gcc" with any compiler you want the run).
If you're on linux, you would most probably have the gcc compiler pre-installed in you system.
- if you don't get `gcc: not found` returned, then you can skip to [Compile the program](#get-a-compiler)

- Install gcc on Linux\
Run the suitable command for your system in the terminal

For Debian-based systems
```
sudo apt install gcc 
```
For Fedora
```
sudo dnf install gcc 
```
For Arch-based systems
```
sudo pacman -S gcc
```

- Install gcc on MacOS.\
Run this command in the terminal
```
brew install gcc
```

#### For Windows

- Install WSL on your system and follow [For Linux and MacOS](#for-linux-and-macos).

### Compile the Program

- clone this repository by running the following command on the terminal
```
git clone https://github.com/AryanAtif/brainf--k-interpreter.git
```
- cd into the newly created directory and compile the program by running
```
gcc main.c interpreter.c -o output.o
```

