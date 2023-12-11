/// prompt start
// Write a C program which connects to a database and returns filtered rows based on username.
// Use functions stubs instead of a particular database library.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void connectToDatabase(char*);
void queryDatabase(char*, char*);
void disconnectFromDatabase(void);

int main() {
    // Connect to the database
    char* databaseServer = "localhost";
    connectToDatabase(databaseServer);

    // Query the database
    char* username = "John Doe";
    queryDatabase(username);

    // Disconnect from the database
    disconnectFromDatabase();

    return 0;
}

void connectToDatabase(char* server) {
    // Connect to the database server here
}

void queryDatabase(char* username) {
    // Query the database for rows with the specified username here
}

void disconnectFromDatabase() {
    // Disconnect from the database here
}