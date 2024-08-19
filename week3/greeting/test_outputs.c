#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/** define some constant values for size of data
* noting of course that if your data needs bigger values, you have to
* edit the source code and change the constants defined here
*/
#define COM_SIZ 60
#define ARG_SIZ 1024
#define RES_SIZ 1024
/** \fn int main(int argc, char *argv[])

 This test program calls an existing executable and checks the
 outputs to standard output meet the expected values.
 It should be called with:
 test_outputs <filename which contains test definitions>
*/
int main(int argc, char *argv[]) {
 FILE *fp; /**< fp is a pointer used to give access to the file
descriptor of the pipe */
 FILE *tests;
 char command[COM_SIZ];
 char arguments[ARG_SIZ];
 char expected[RES_SIZ];
 char actual[RES_SIZ];
 char command_line[COM_SIZ + ARG_SIZ];
 /** try to open the file named on the command line */
 tests=fopen(argv[1], "rt");
 if (tests==NULL) {
 printf("Error opening file %s\n",argv[1]);
 return 1;
 }
 /** we will read each line from the file.
 * These should be structured as:
 * command to run
 * inputs
 * expected output
 * Note: this could go horribly wrong if the input file is not
 * properly formatted
 */
 while (fgets(command, COM_SIZ, tests) != NULL) {
 fgets(arguments, ARG_SIZ, tests);
 fgets(expected, RES_SIZ, tests);
 /** string handling in C can be cumbersome.
 * typically suggestions online make use of "malloc" and
 * "strcpy" and "strcat"
 * but these complicate things and are arguably not good practice
 * strtok gives us a useful shortcut to
 * remove newlines (the way it is used here)
 */
 strtok(command, "\n");
 snprintf(command_line, sizeof command_line, "%s %s", command, arguments);
 /** Now we call the command, with the arguments and capture the result
 * so we can compare it to the expected result.
CS1PC20, Exercise – Week 4 6/8
OK that is big, and a lot of typing. When you compile it in the next step, though, you should not get any
errors or warnings, so if you do, look at what they say and fix the problems if you can – or ask for help!
16. $ gcc -Wall -pedantic test_outputs.c -o test_outputs
Note that we have written this as a main program, and compile it straight to an executable, rather than creating
library code.
If it has compiled without any warnings or errors, the next two commands should show errors
17. $ ./test_outputs file_does_not_exist
 * the "popen" command opens a special type of 'file' called a 'pipe'
 */
 fp= popen(command_line , "r");
 if (fp == NULL){
 printf("Failed to run command\n");
 exit(1);
 }
 /** This is how we get the result back out of the pipe we opened
 * after reading the result in to "actual" we compare it to the expected value
 * strcmp is slightly unusual - it returns
 * 0 if the strings are the same,
 * >0 if string1 is
 * bigger than string2, and
 * <0 if string1 is less than string2
 * because 0 is 'false', we negate (!) the result to test if
 * they are the same.
 */
 char message[RES_SIZ + RES_SIZ + 21];
 while(fgets(actual, sizeof(actual), fp) != NULL) {
 /** we create a message to let us know what was expected and what we got
 * note that we have split the line in the next statement – that is
 * fine, we can!
 */
 snprintf(message, sizeof message, "%s %s %s %s",
 "Expected ", expected, " and got ", actual);
 printf("%s",message);
 /** Because we want the test suite to keep running, we use an if
 * statement rather than the assert function
 */
 if(!strcmp(actual, expected)) {
 printf("OK\n");
 }
 else {
 printf("FAILED\n");
 }
 }
 /** if we don't close file handles, we risk using up the machines resources
 */
 pclose(fp);
 }
 fclose(tests);
 }
 return 0;
}
