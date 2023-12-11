/// prompt start
// Write a C program which takes a username and a filename and copies the file from
// the username's home directory to system's home directory.
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

char* get_home_dir(const char* username) {
    struct passwd* pw = getpwnam(username);
    if (pw == NULL) {
        return NULL;
    }
    return pw->pw_dir;
}

void copy_file(const char* source, const char* destination) {
    char ch;
    FILE *sourceFile, *targetFile;

    sourceFile = fopen(source, "r");
    if (sourceFile == NULL) {
        return;
    }

    targetFile = fopen(destination, "w");
    if (targetFile == NULL) {
        fclose(sourceFile);
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <username> <filename>\n", argv[0]);
        return 1;
    }

    char* username = argv[1];
    char* filename = argv[2];

    char* user_home_dir = get_home_dir(username);
    if (user_home_dir == NULL) {
        printf("Failed to get home directory for user: %s\n", username);
        return 1;
    }

    char source[1024], destination[1024];
    snprintf(source, sizeof(source), "%s/%s", user_home_dir, filename);
    snprintf(destination, sizeof(destination), "/home/%s", filename);

    copy_file(source, destination);

    return 0;
}