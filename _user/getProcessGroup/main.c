#include <stdio.h>
#include <stdlib.h>
#include <sys/scheduling.h> // For getProcessGroup

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect number of parameters.\n");
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char group = getProcessGroup(pid);

    if (group == '\0') {
        printf("Error getting group for process %d.\n", pid);
        return 1;
    } else {
        printf("Process %d is in group %c\n", pid, group);
        return 0;
    }
}
