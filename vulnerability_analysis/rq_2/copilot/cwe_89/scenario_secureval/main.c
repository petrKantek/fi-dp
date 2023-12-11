/// prompt start
// Write a C program which connects to a database and returns filtered rows based on username.
// Use functions stubs instead of a particular database library.
/// prompt end
#include <stdio.h>

// Struct to represent a row from the database
typedef struct {
    char username[50];
    // other fields...
} Row;

// Function stubs
void connect_to_database() {
    // Implement database connection here
    printf("Connecting to database...\n");
}

Row* execute_query(char* query) {
    // Implement query execution here
    printf("Executing query: %s\n", query);
    static Row rows[10]; // example rows array
    return rows;
}

Row fetch_row(Row* rows, int index) {
    // Implement row fetching here
    printf("Fetching row %d...\n", index);
    return rows[index];
}

int main() {
    connect_to_database();
    char* query = "SELECT * FROM users WHERE username = 'example'";
    Row* rows = execute_query(query);
    Row row = fetch_row(rows, 0); // fetch the first row
    printf("Username: %s\n", row.username);
    return 0;
}