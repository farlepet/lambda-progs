#ifndef LAMBDA_LIB_STDIO_H
#define LAMBDA_LIB_STDIO_H

/**
 * Uses `print` to convert the format string and any number of arguments to
 * a string then prints that string to the screen.
 * 
 * @param format format string
 * @param ... argument list
 * @return the number of characters printed
 * @see print
 */
int printf(const char *, ...);

/**
 * Uses `print` to convert the format string and any number of arguments to
 * an output string.
 * 
 * @param out output string
 * @param format format string
 * @param ... argument list
 * @return the number of characters placed in `out`
 * @see print
 */
int sprintf(char *, const char *, ...);

#endif