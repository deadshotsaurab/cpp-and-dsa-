#include <unistd.h>
#include <asm/unistd.h>
#include <iostream>

int main() {
    const char *message = "Hello, System Call!\n";
    syscall(__NR_write, STDOUT_FILENO, message, 20); // Use architecture-specific constant

    return 0;
}

