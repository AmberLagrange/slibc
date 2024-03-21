extern int main(int argc, char *argv[]);
extern void exit(int status);

/* naked attribute to ignore setting up the function's prologue */
/* NOLINTNEXTLINE(bugprone-reserved-identifier) */
void __attribute((naked)) _start(void) {
    __asm__ volatile (
        "movl (%rsp), %edi          \n\t" /* move argc into edi */
        "lea 8(%rsp), %rsi          \n\t" /* move the address of argv into rsi */
        "call __slibc_start_main    \n\t" /* call __slibc_start_main with argc and argv */
    );
}

/* NOLINTNEXTLINE(bugprone-reserved-identifier) */
void __slibc_start_main(int argc, char *argv[])
{
    int result = main(argc, argv);

    exit(result);
}
