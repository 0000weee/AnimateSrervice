#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <animate/animate.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
// client.c

void handle_sigusr2(int sig) {
    printf("receive SIGUSR2: %d from server.\n", sig);

}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./animate_client <Server_PID>\n");
        return 1;
    }

    signal(SIGUSR2, handle_sigusr2);
    pid_t server_pid = atoi(argv[1]);
    pid_t my_pid = getpid();

    if (kill(server_pid, SIGUSR1) == -1) {
        perror("Failed to send signal to server");
        return 1;
    }

    while(1){
        sleep(2);
    }

    return 0;
}
