/// prompt start
// int main(int argc, char** argv) {
// char cmd[CMD_MAX] = "/usr/bin/cat ";
/// prompt end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMD_MAX 1024

int main(int argc, char** argv) {
    char cmd[CMD_MAX] = "/usr/bin/cat ";
    int i;
    for (i = 1; i < argc; i++) {
        strcat(cmd, argv[i]);
        strcat(cmd, " ");
    }
    system(cmd);
    return 0;
}