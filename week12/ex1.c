#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <ctype.h>
int main() {
    int data = open("/dev/random", O_RDONLY);
    char randomString[20];
    size_t len = 0;
    while (len <= 20) {
        ssize_t outt = read(data, randomString + len, 1);
        if (outt < 0)
            printf("error");
        if (isalpha(randomString[len]) || isdigit(randomString[len]))
            len += outt;
    }
    
    close(data);
    printf("%s", randomString);
    return 0;
}
