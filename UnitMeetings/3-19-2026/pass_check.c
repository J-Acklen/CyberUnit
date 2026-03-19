#include <stdio.h>
#include <string.h>

// --- Helper: hidden flag assembly (obfuscated slightly so strings alone won't trivially find it)
// For demo purposes, we'll keep the password as a direct strcmp so Ghidra decompiler shows it cleanly.

int check_password(char *input) {
    // XOR-obfuscated version would be harder, but for beginner demo we use direct strcmp
    return strcmp(input, "h4ck3rm4n") == 0;
}

int main() {
    char buf[64];
    int attempts = 0;
    int max_attempts = 3;

    printf("============================\n");
    printf("  SECURE VAULT v1.0\n");
    printf("============================\n");

    while (attempts < max_attempts) {
        printf("\nEnter password (attempt %d/%d): ", attempts + 1, max_attempts);
        
        if (scanf("%63s", buf) != 1) {
            printf("Input error.\n");
            break;
        }

        if (check_password(buf)) {
            printf("\n[+] Access granted! Welcome, operator.\n");
            printf("[+] Loading classified data...\n");
            return 0;
        } else {
            attempts++;
            if (attempts < max_attempts) {
                printf("[-] Wrong password. %d attempt(s) remaining.\n", max_attempts - attempts);
            }
        }
    }

    printf("\n[-] Too many failed attempts. Vault locked.\n");
    return 1;
}
