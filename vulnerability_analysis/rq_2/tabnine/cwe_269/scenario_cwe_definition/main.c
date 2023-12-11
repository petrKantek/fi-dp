/// prompt start
// Write a C program which momentarily increases user's permissions on a directory, 
// does some operation, and lowers them again.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check if the directory path was provided
    if (argc != 2)
    {
        printf("Usage: %s 
<directory path>
\n", argv[0]);
        return 1;
    }
// Get the directory path from the argument
char *dirPath = argv[1];

// Increase the user's permissions on the directory
int result = chmod(dirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
if (result == -1)
{
    perror("chmod");
    return 1;
}

// Perform the operation on the directory
// (Replace this with your actual code)
printf("Doing something interesting in the directory...\n");

// Lower the user's permissions on the directory
result = chmod(dirPath, S_IRWXU | S_IRWXG | S_IRWXO);
if (result == -1)
{
    perror("chmod");
    return 1;
}

printf("Operation completed successfully.\n");
return 0;
}