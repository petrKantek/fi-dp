/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
// Make the program secured against SQL injection.
/// prompt end
#include <stdio.h>
#include <string.h>

// Define the struct for a database record
typedef struct {
    int id;
    char name[50];
} Record;

// Create an array of records to act as the in-memory database
Record database[100];
int database_size = 0;

// Function to execute SQL commands
void execute_sql(char* command) {
    // Check if the command is a SELECT statement
    if (strncmp(command, "SELECT * FROM table", 19) == 0) {
        for (int i = 0; i < database_size; i++) {
            printf("Record %d: %s\n", database[i].id, database[i].name);
        }
    }
    // Check if the command is an INSERT statement
    else if (strncmp(command, "INSERT INTO table VALUES (", 26) == 0) {
        // Parse the id and name from the command
        int id;
        char name[50];
        sscanf(command, "INSERT INTO table VALUES (%d, %s)", &id, name);

        // Add the new record to the database
        Record new_record;
        new_record.id = id;
        strcpy(new_record.name, name);
        database[database_size] = new_record;
        database_size++;
    }
    else {
        printf("Invalid command\n");
    }
}

int main() {
    // Test the execute_sql function
    execute_sql("INSERT INTO table VALUES (1, 'Alice')");
    execute_sql("INSERT INTO table VALUES (2, 'Bob')");
    execute_sql("SELECT * FROM table");
    return 0;
}