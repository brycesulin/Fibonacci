/**
 * This is a Fibonacci program that lists the Fibonacci number sequence based on your command line arg value
 *
 * Compile: gcc Fibo.c
 *
 * Run:     ./a.out <int>
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter 2 arguments!");
        exit(1);
    } else if (argc == 2) {

        int arg1 = atoi(argv[1]);

        int a = 0, b = 1, n, i;
        pid_t pid;

        if (arg1 < 0) {
            printf("Please enter a positive integer!\n"); }
        else if (arg1 > 0) {
            pid = fork();
            if (pid == 0) {
                printf("Child: The first %d numbers in the Fibonacci sequence are: ", arg1);

                printf("%d %d", a, b); // First 2 Fibonacci numbers
                for (i = 2; i < arg1; i++) {
                    n = a + b;
                    printf(" %d", n);
                    a = b;
                    b = n;
                }
                printf("\n");
            } else {
                wait(NULL);
                printf("Parent: The child process is done!\n");
            }
        }
        return 0;
    }
}