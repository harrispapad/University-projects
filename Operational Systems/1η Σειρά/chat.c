#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define NUM_CHILDREN 5

int fdi;
int fdo;
char cw;
char *input_file;
char *output_file;

void open_file();
void search();
void write_result();
void close_file();
void handle_sigint(int sig);

void father(int pipefds[][2]);
void child(int pipefds[][2], int child_index);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input_file output_file character\n", argv[0]);
        exit(1);
    }

    input_file = argv[1];
    output_file = argv[2];
    cw = argv[3][0];

    open_file();

    int pipefds[NUM_CHILDREN][2];

    // Create pipes for communication between parent and child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(pipefds[i]) == -1) {
            perror("Pipe");
            exit(1);
        }
    }

    pid_t p;

    // Create child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        p = fork();

        if (p < 0) {
            perror("Fork");
            exit(1);
        } else if (p == 0) {
            child(pipefds, i);
            exit(0);
        }
    }

    signal(SIGINT, handle_sigint);

    father(pipefds);

    close_file();

    return 0;
}

void open_file() {
    fdi = open(input_file, O_RDONLY);
    if (fdi == -1) {
        perror("Error opening input file");
        exit(1);
    }
}

void search(int pipefd_write) {
    char c;
    char buff[1];
    ssize_t sz;
    int counter = 0;

    do {
        sz = read(fdi, buff, 1);

        if (sz == -1) {
            perror("Error reading input file");
            exit(1);
        }

        c = buff[0];
        if (c == cw)
            counter++;
    } while (sz > 0);

    // Write the counter value to the pipe
    if (write(pipefd_write, &counter, sizeof(counter)) == -1) {
        perror("Error writing to pipe");
        exit(1);
    }
}

void write_result(int total_counter) {
    fdo = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 00700);
    if (fdo == -1) {
        perror("Error opening output file");
        exit(1);
    }

    char buffer[70];
    int len = snprintf(buffer, sizeof(buffer), "The character '%c' was found %d times in your file!\n", cw, total_counter);
    ssize_t out = write(fdo, buffer, len);

    if (out == -1) {
        perror("Error writing output file");
        exit(1);
    }
}

void close_file() {
    if (close(fdo) == -1) {
        perror("Error closing output file");
        exit(1);
    }
}

void handle_sigint(int sig) {
    printf("Total number of child processes searching the file: %d\n", NUM_CHILDREN);
    exit(0);
}

void father(int pipefds[][2]) {
    printf("This is process %d.\n", getpid());

    int total_counter = 0;
    int child_counter;

    // Close the write ends of all pipes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        close(pipefds[i][1]);
    }

    // Read counters from each child process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (read(pipefds[i][0], &child_counter, sizeof(child_counter)) == -1) {
            perror("Error reading from pipe");
            exit(1);
        }
        total_counter += child_counter;
    }

    write_result(total_counter);
}

void child(int pipefds[][2], int child_index) {
    printf("Hello! I am process %d and my father is process %d.\n", getpid(), getppid());

    // Close the read ends of all pipes except the one for this child process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (i != child_index)
            close(pipefds[i][0]);
    }

    search(pipefds[child_index][1]);

    // Close the write end of this child's pipe after writing
    close(pipefds[child_index][1]);
}
