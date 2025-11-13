#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        sleep(5);
        printf("Child process (Orphan): Parent PID = %d\n", getppid());
    } else {
        printf("Parent process exiting.\n");
    }
}