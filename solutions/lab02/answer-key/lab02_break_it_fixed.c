/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-27
 * Lab      : Lab 02: Program Structure & Basic I/O
 * Filename : lab02_break_it_fixed.c
 * Description: Corrected name card program; the comment below records the
 *              compiler errors observed while deliberately breaking it.
 */

/*
 * Errors observed during the "break it and read the error" exercise
 * (gcc -Wall -Wextra -std=c99). Each was reproduced directly against
 * this exact file, not paraphrased from memory - your compiler's exact
 * wording may differ slightly by gcc version, but the shape will match.
 *
 * 1. Removed the semicolon after the first printf statement:
 *      break1.c:14:46: error: expected ';' before 'printf'
 *         14 |     printf("+---------------------------+\n")
 *            |                                              ^
 *            |                                              ;
 *    Meaning: the compiler finished reading the printf call and expected
 *    a ';' right after it, but found the next printf instead - a
 *    statement is missing its terminating semicolon. Fix: put the ';'
 *    back at the end of line 14.
 *
 * 2. Removed the line '#include <stdio.h>':
 *      break2.c:13:5: error: implicit declaration of function 'printf'
 *      [-Wimplicit-function-declaration]
 *      break2.c:1:1: note: include '<stdio.h>' or provide a
 *      declaration of 'printf'
 *    Meaning: the compiler does not know what printf is because the
 *    standard I/O library was never included. On this toolchain
 *    (gcc 15) this is a hard error, not just a warning - the build
 *    fails. Fix: restore the include.
 *
 * 3. Changed 'main' to 'Main' (case sensitivity demo):
 *      ld.bfd: ...Scrt1.o: in function '_start':
 *      (.text+0x1b): undefined reference to 'main'
 *      collect2: error: ld returned 1 exit status
 *    Meaning: C is case sensitive, so 'Main' is a different name and the
 *    program has no entry point named 'main'. This error comes from the
 *    linker (ld), not the compiler itself - the exact library paths in
 *    the message will differ by machine, but "undefined reference to
 *    'main'" is the part that matters. Fix: rename it back to lowercase
 *    'main'.
 */
#include <stdio.h>

int main(void) {
    printf("+---------------------------+\n");
    printf("| Name : Reference Solution |\n");
    printf("| ID   : N/A                |\n");
    printf("| Lab  : Computer Prog. I   |\n");
    printf("+---------------------------+\n");
    return 0;
}
