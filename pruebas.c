#include <stdio.h>
#include <signal.h>

void handleSignal(int signum) {
    // Do nothing
}

int main() {
    char line[256];

    // Set up the sigaction structure
    struct sigaction sa;
    sa.sa_handler = handleSignal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    // Set the action for SIGINT
    sigaction(SIGINT, &sa, NULL);

    for (int i = 0; i < 3; i++) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            printf("%s", line);
        } else {
            break; // Reached end of input
        }
    }

    return 0;
}
