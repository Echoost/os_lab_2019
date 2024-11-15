#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Дочерний процесс: выполняем `sequential_min_max`
        if (execv("./sequential_min_max", argv) == -1) {
            perror("exec failed");
            exit(1);
        }
    } else {
        // Родительский процесс: ждем завершения дочернего процесса
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("sequential_min_max finished with exit code %d\n", WEXITSTATUS(status));
        } else {
            printf("sequential_min_max did not terminate normally\n");
        }
    }

    return 0;
}
