#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char message[10];
    int buffer = setvbuf(stdout,  message, _IOLBF, 5);
    // Putting in buffer
    printf('H');
    sleep(1);
    printf('e');
    sleep(1);
    printf('l');
    sleep(1);
    printf('l');
    sleep(1);
    printf('o');
    sleep(1);
    // Printing the entire buffer
    setbuf(stdout, message);
    return 0;
}
