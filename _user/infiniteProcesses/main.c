#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For pid_t and fork()
#include <sys/scheduling.h> // For setProcessGroup

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <Groups>\n", argv[0]); // Only need the group string now
        return 1;
    }
    
    char *groups = argv[1];
    
    // Create one child for each character in the group string
    for (int i = 0; groups[i] != '\0'; ++i) {
        char group = groups[i];
        
        // Check if the group is valid
        if (group != 'A' && group != 'B' && group != 'C') {
            printf("Invalid group: %c. Please specify 'A', 'B', or 'C' in the group string.\n", group);
            continue; // Skip this iteration
        }
        
        pid_t pid = fork();
        
        if (pid == 0) { // Child
            // Set the process group
            if (setProcessGroup(getpid(), group) != 0) {
                printf("Failed to set group %c for child process\n", group);
                return 1; // Child exits with failure
            }
            
            printf("Child in group %c started.\n", group);
            while (1); // Infinite loop
        }
        // Parent continues to create more children
    }
    
    // Parent process waits for children to prevent them from becoming zombies
    for (int i = 0; groups[i] != '\0'; ++i) {
        wait(NULL);
    }
    
    return 0; // This line will never be reached
}
