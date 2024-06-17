#include <stdio.h>
#include <stdlib.h>
#include <sys/scheduling.h> // For setProcessGroup

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect number of parameters.\n");
        printf("Usage: %s <PID> <Group>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char group = argv[2][0];

    if (group != 'A' && group != 'B' && group != 'C') {
        printf("Invalid group: %c. Please specify 'A', 'B', or 'C'.\n", group);
        return 1;
    }

    if (setProcessGroup(pid, group) != 0) {
        printf("Error setting group %c for process %d.\n", group, pid);
        return 1;
    } else {
        printf("Group for process %d set to: %c\n", pid, group);
        return 0;
    }
}
