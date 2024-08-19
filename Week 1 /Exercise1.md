Edit it to see in proper format

command
what i think happens
     more stuff that might happens
what happens
     More stuff that heppens

mkdir -p $HOME/portfolio/week1 ; cd $HOME/portfolio/week1 
Creates a directory
Creates and enters a directory

cd ~ 
Leaves current directory
Leaves current directory

rm -r portfolio
deletes directory
deletes direcotry

mkdir -p $HOME/portfolio/week1 & cd $HOME/portfolio/week1 
Creates and enters a directory
Doesnt work

cd ~
Goes back to default directory
Leaves current directory

rm -r portfolio
deletes directory
deletes directory

mkdir -p $HOME/portfolio/week1 && cd $HOME/portfolio/week1 
Creates and enters a directory
Creates and enters a directory

echo "Hello World"
prints: Hello World
prints: Hello World

echo Hello, World
prints: Hello World
prints: Hello World

echo Hello, world; Foo bar 11. $ echo Hello, world!
prints: Hello World Hello, world!
does not work

echo "line one";echo "line two"
Prints: Line one
        Line two   
        (On 2 seprate lines)
Prints: Line one
        Line two   
        (On 2 seprate lines)

echo "Hello, world > readme"
Prints: Hello, world > readme
Prints: Hello, world > readme

echo "Hello, world" > readme
Prints: Hello, world
        Stores it in a variable called readme
Stores it in a variable called readme

cat readme
Prints out what is in readme
Prints out what is in readme (Hello, world)

example="Hello, World"
Creates variable called example and stores Hello, World in it
Creates variable called example and stores Hello, World in it

echo $example
Prints what is in example
Prints what is in example (Hello, World)

echo ’$example’
Prints what is in example
Doesnt work

echo "$example"
Prints what is in example
Prints what is in example (Hello, World)

echo "Please enter your name."; read example
Prints: Please enter your name
        Reads what is in example
Prints: Please enter your name
        allows user to enter name
        stores name in example

echo "Hello $example"
Prints: Hello $example
Prints: Hello Felix
     (Felix was what was in example)

three=1+1+1;echo $three
makes variable called three and stores 1+1+1
     Prints what is in 3
makes variable called three and stores 1+1+1
     Prints what is in 3

bc
No clue
Prints copyright stuff
     exits student vm

echo 1+1+1 | bc
no clue
Prints: 3

let three=1+1+1;echo $three
no clue
Prints: 3

echo date 
Prints the date
Prints the date

cal
Prints out a calnder 
Prints out a calander and highlights todays date

which cal
No clue
Gives directory of where calander is stored

/bin/cal
Stores a calnder in this directory
Prints out the callender in /bin/cal

$(which cal)
Crash
Prints a callender

‘which cal‘
Prints a calander
No command found

echo "The date is $(date)"
Prints: The date is (current date)
Prints: The date is (current date)

seq 0 9
Prints: 0 1 2 3 4 5 6 7 8 9 
Prints: 0 1 2 3 4 5 6 7 8 9

seq 0 9 | wc -l
Prints: 0 1 2 3 4 5 6 7 8 9 
Prints: 10
     (length of sequence)?

seq 0 9 > sequence
Stores 0 1 2 3 4 5 6 7 8 9  into sequence
Not sure

wc -l < sequence
Prints length of sequence in sequence
Prints: 10  
     Prints length of sequence in sequence

for I in $(seq 1 9) ; do echo $I ; done
Prints: 0 1 2 3 4 5 6 7 8 9 
Prints: 0 1 2 3 4 5 6 7 8 9

(echo -n 0 ; for I in $(seq 1 9) ; do echo -n +$I ; done ; echo) | bc
Not sure
Error (bad typing?)

echo -e ‘#include <stdio.h>\nint main(void) \n{\n printf(“Hello World\\n”);\n return 0;\n}’ > hello.c 
Not sure
Error (bad typing?)

cat hello.c
Not sure
Cant find directory

gcc hello.c -o hello
Not sure
Error

./hello
Not sure
Cant find directory
