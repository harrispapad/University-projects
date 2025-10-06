#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define P 5

int fdi;
int fdo;
char cw;
char *input_file;
char *output_file;
int pipefds[P][2];

// Signal handler for SIGINT
void handle_sigint(int sig) {
    printf("Child processes working on the file: %d\n", P);
}

void open_file() {
    fdi = open(input_file, O_RDONLY);
    if (fdi == -1) {
        perror("Error opening input file.\n");
        exit(1);
    }
}

void search(int current_pipe) {
    char c;
    ssize_t sz;
    int counter = 0;

    do {
        sz = read(fdi, &c, 1);
        if (sz == -1) {
            perror("Error reading input file.\n");
            exit(1);
        }
        if (c == cw)
            counter++;
    } while (sz > 0);

    if (write(current_pipe, &counter, sizeof(counter)) == -1) {
        perror("Error writing to pipe.\n");
        exit(1);
    }
}

void write_result(int total_counter) {
    fdo = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 00700);
    if (fdo == -1) {
        perror("Error opening output file.\n");
        exit(1);
    }

    char buffer[70];
    int len = snprintf(buffer, sizeof(buffer), "The character '%c' was found %d times in your file.\n", cw, total_counter);

    if (write(fdo, buffer, len) == -1) {
        perror("Error writing output file.\n");
        exit(1);
    }

    if (close(fdo) == -1) {
        perror("Error closing output file.\n");
        exit(1);
    }
}

void close_file() {
    if (close(fdi) == -1) {
        perror("Error closing input file.\n");
        exit(1);
    }
}

void father() {
    int total_counter = 0;
    int child_counter;

    for (int i = 0; i < P; i++) {
        close(pipefds[i][1]); // Close write end of pipes not used by parent
    }

    // Loop to read from each child process and accumulate the total counter
    for (int i = 0; i < P; i++) {
        do {
            if (read(pipefds[i][0], &child_counter, sizeof(child_counter)) == -1) {
                if (errno == EINTR)
                    continue; // Retry if interrupted by signal
                else {
                    perror("Error reading from pipe.\n");
                    exit(1);
                }
            }
            total_counter += child_counter;
        } while (1); // Loop until we successfully read from the pipe
    }

    write_result(total_counter);
}

void child(int child_number) {
    for (int i = 0; i < P; i++) {
        if (i != child_number)
            close(pipefds[i][0]); // Close read end of pipes not used by this child
    }

    search(pipefds[child_number][1]);

    close(pipefds[child_number][1]); // Close write end of this child's pipe
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Syntax: ./q3 'input_file' 'output_file' 'character'\n");
        exit(1);
    }

    input_file = argv[1];
    output_file = argv[2];
    cw = argv[3][0];

    open_file();

    for (int i = 0; i < P; i++) {
        if (pipe(pipefds[i]) == -1) {
            perror("Error during making pipe\n");
            exit(1);
        }
    }

    pid_t p;
    for (int i = 0; i < P; i++) {
        p = fork();
        if (p < 0) {
            perror("Error during Fork.\n");
            exit(1);
        } else if (p == 0) {
            // Child processes completely ignore SIGINT
            signal(SIGINT, SIG_IGN);
            child(i);
            exit(0);
        }
    }

    // Set up signal handler for SIGINT in the parent process
    signal(SIGINT, handle_sigint);

    father();

    close_file();

    sleep(2); // Sleep for 5 seconds to test behavior

    return 0;
}

