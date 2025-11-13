#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process finished.\n");
    } else {
        sleep(10);
        printf("Parent running while child is zombie.\n");
    }
}