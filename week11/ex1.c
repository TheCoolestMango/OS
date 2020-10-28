#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int File = open("ex1.txt", O_RDWR | O_TRUNC, (mode_t)0700);
    char *message = "This is a nice day";
    ftruncate(File, strlen(message) );
    char *map = mmap(NULL, strlen(message), PROT_READ|PROT_WRITE, MAP_SHARED, File,0);
    memcpy(memory, string, strlen(message) );
    msync(memory, strlen(message)-1, MS_ASYNC);
    munmap(memory, strlen(message)-1);
    return 0;
}
