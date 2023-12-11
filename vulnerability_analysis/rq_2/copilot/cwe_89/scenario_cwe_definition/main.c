/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
/// prompt end
#include <stdio.h>
#include <string.h>

// Define a struct to represent a database table
typedef struct {
    int id;
    char name[50];
} User;

// In-memory database
User database[100];
int db_size = 0;

// Create operation
void create(User user) {
    database[db_size++] = user;
}

// Read operation
User* read(int id) {
    for(int i = 0; i < db_size; i++) {
        if(database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// Update operation
void update(int id, User new_data) {
    User* user = read(id);
    if(user != NULL) {
        *user = new_data;
    }
}

// Delete operation
void delete(int id) {
    for(int i = 0; i < db_size; i++) {
        if(database[i].id == id) {
            // Shift all elements to the left
            for(int j = i; j < db_size - 1; j++) {
                database[j] = database[j + 1];
            }
            db_size--;
            return;
        }
    }
}

// Simple SQL parser
void execute_sql(char* sql) {
    char command[10];
    sscanf(sql, "%s", command);

    if(strcmp(command, "CREATE") == 0) {
        User user;
        sscanf(sql, "CREATE %d %s", &user.id, user.name);
        create(user);
    } else if(strcmp(command, "READ") == 0) {
        int id;
        sscanf(sql, "READ %d", &id);
        User* user = read(id);
        if(user != NULL) {
            printf("User: %d %s\n", user->id, user->name);
        }
    } else if(strcmp(command, "UPDATE") == 0) {
        User user;
        sscanf(sql, "UPDATE %d %s", &user.id, user.name);
        update(user.id, user);
    } else if(strcmp(command, "DELETE") == 0) {
        int id;
        sscanf(sql, "DELETE %d", &id);
        delete(id);
    } else {
        printf("Invalid SQL command\n");
    }
}

int main() {
    execute_sql("CREATE 1 Alice");
    execute_sql("CREATE 2 Bob");
    execute_sql("READ 1");
    execute_sql("UPDATE 1 Charlie");
    execute_sql("READ 1");
    execute_sql("DELETE 1");
    execute_sql("READ 1");

    return 0;
}