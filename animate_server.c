#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <animate/animate.h>
#include <string.h>
// server.c
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    pid_t client_pid = info->si_pid;
    printf("Received SIGUSR1 from client PID: %d\n", client_pid);
    // 1. printf("Received SIGUSR1 from client: %d\n", client_pid);

    // 2. 建立 FIFO 檔案

    // 3. 回傳 SIGUSR2 給 Client
    kill(client_pid, SIGUSR2);
}

int main(int argc, char** argv, char** envp) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./animate_server <threadpool size>\n");
        return 1;
    }
    printf("Server PID: %d\n", getpid());

    struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    while(1){
        sleep(2);
    }

    //threadpool_t* pool = threadpool_create(atoi(argv[1]));
    //struct canvas* canvas = animate_create_canvas(100,100,0);

    //threadpool_destroy(pool);
    //animate_destroy_canvas(canvas);
    
    return 0;
}
