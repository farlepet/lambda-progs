#ifndef LAMBDA_LIB_STDIO_FMT_H
#define LAMBDA_LIB_STDIO_FMT_H

#include <stdint.h>

#define FMT_SPEC '%' //!< Format specifier character

typedef uint32_t arg_t;

#define va_arg __builtin_va_arg // Helps clean up the code a bit

#define ZERO_ALL_VID()  \
do {                \
    is_in_spec = 0; \
    size       = 0; \
    width      = 0; \
    precision  = 0; \
    showsign   = 0; \
    signspace  = 0; \
    leftalign  = 0; \
    padzeros   = 0; \
} while(0);

/**
 * Converts an integer into a string and places the output into `out`
 * Used by `print` to make the code cleaner.
 * 
 * @param num the number to print
 * @param base the base in which to print the number
 * @param u wether the number is unsigned
 * @param pad how many characters of padding to give the number
 * @param padzero wether or not to pad the number with zeros instead of spaces
 * @param possign wether or not to place a positive sign in front of positive numbers
 * @param posspace wether or not to place a space in front of positive numbers
 * @param _case upper or lowercase (for bases above 10)
 * @param out the output string/buffer
 * @return the number of characters that have been put in `out`
 * @see print
 */
int print_int(uint32_t num, uint8_t base, uint8_t u, uint8_t pad, uint8_t padzero, uint8_t possign, uint8_t posspace, uint8_t _case, char *out);

/**
 * Convert a number in a string into an integer. Used by `print` to make code cleaner.
 * 
 * @param str input string
 * @param out pointer to end of number (generated by this function)
 * @return the number found
 * @see print
 */
int get_dec(const char *str, arg_t *out);

/**
 * Takes a format string and a list of arguments as input, and produces a
 * string as output.
 * 
 * @param out the output string
 * @param format the format string
 * @param varg the list of arguments
 * @return the number of charactern placed in `out`
 */
int print(char *out, const char *format, __builtin_va_list varg);

#endif