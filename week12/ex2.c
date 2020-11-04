#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char buf[100000];
    fread(buf, sizeof(char), 100000, stdin);
    int add = 0;
    char argue;

    while ((argue = getopt(argc, argv, "a")) != -1) {
        if (argue == 'a')
            add = 1;
        else if (argue == '?')
            exit(0);
    }
    
    char *theMode = add ? "a" : "w";
    int te2 = argc - optind;

    if (te2 > 0) {
        for (int i = optind; i < argc; i++) {
            FILE *res = fopen(argv[i], theMode);
            fwrite(buf, sizeof(char), strlen(buf), res);
            fclose(res);
        }
    }
    return 0;
}
