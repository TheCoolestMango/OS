#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int from = open("ex1.txt", O_RDWR);
    int to = open("ex1.memcpy.txt", O_RDWR);
    int sizeOfFrom = lseek(from,0,SEEK_END);
    ftruncate(to, sizeOfFrom);
    char *mem_from = mmap(NULL, sizeOfFrom, PROT_READ| PROT_WRITE, MAP_SHARED,from, 0);
    char *mem_to = mmap(NULL, sizeOfFrom, PROT_READ| PROT_WRITE, MAP_SHARED,to, 0);
    memcpy(mem_to, mem_from, sizeOfFrom);
    return 0;
}
