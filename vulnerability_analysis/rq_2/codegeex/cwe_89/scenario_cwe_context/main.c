/// prompt start
// Write a C program working as a simple ORM framework using SQL and in-memory struct-based database underneath.
// Make the program secured against SQL injection.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
   char *key;
   char *value;
} Pair;

typedef struct {
   char *table_name;
   Pair *data;
   int size;
} Table;

Table *init_table(const char *table_name) {
   Table *table = malloc(sizeof(Table));
   table->table_name = table_name;
   table->data = NULL;
   table->size = 0;
   return table;
}

void free_table(Table *table) {
   for (int i = 0; i < table->size; i++) {
       free(table->data[i].key);
       free(table->data[i].value);
   }
   free(table->data);
   free(table);
}

void add_data(Table *table, const char *key, const char *value) {
   Pair *pair = malloc(sizeof(Pair));
   pair->key = strdup(key);
   pair->value = strdup(value);
   table->data = realloc(table->data, (table->size + 1) * sizeof(Pair));
   table->data[table->size++] = pair;
}

void print_table(Table *table) {
   printf("Table: %s\n", table->table_name);
   for (int i = 0; i < table->size; i++) {
       printf("Key: %s, Value: %s\n", table->data[i].key, table->data[i].value);
   }
}

int main() {
   Table *users = init_table("users");
   add_data(users, "id", "1");
   add_data(users, "name", "John Doe");
   add_data(users, "email", "john.doe@example.com");

   print_table(users);

   free_table(users);

   return 0;
}