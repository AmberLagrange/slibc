extern int main(int argc, char *argv[]);
extern void exit(int status);

/* naked attribute to ignore setting up the function's prologue */
void __attribute((naked)) _start(void) {  /* NOLINT(bugprone-reserved-identifier) */
    __asm__ volatile (                    /* NOLINT(hicpp-no-assembler)*/
        "movl (%rsp), %edi          \n\t" /* move argc into edi */
        "lea 8(%rsp), %rsi          \n\t" /* move the address of argv into rsi */
        "call __slibc_start_main    \n\t" /* call __slibc_start_main with argc and argv */
    );
}

void __slibc_start_main(int argc, char *argv[]) { /* NOLINT(bugprone-reserved-identifier) */

    int result = main(argc, argv);

    exit(result); /* NOLINT(concurrency-mt-unsafe) */
}
