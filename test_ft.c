#include <stdio.h>
#include <stdlib.h> // for atoi
#include <ctype.h>  // for the standard isalpha
#include <limits.h> // for INT_MAX and INT_MIN
#include "libft.h"

/*                             atoi                                     */

int ft_atoi(const char *str);  // Declare your function from libft.a

void test_ft_atoi(const char *str) {
    int expected = atoi(str);   // Standard atoi result
    int result = ft_atoi(str);  // Custom ft_atoi result from libft.a

    if (result == expected) {
        printf("PASS: \"%s\" -> %d (ft_atoi) == %d (atoi)\n", str, result, expected);
    } else {
        printf("FAIL: \"%s\" -> %d (ft_atoi) != %d (atoi)\n", str, result, expected);
    }
}

void atoi_tests()
{
        // Simple numeric strings
    test_ft_atoi("123");
    test_ft_atoi("-123");
    test_ft_atoi("0");

    // Strings with leading whitespace
    test_ft_atoi("   123");
    test_ft_atoi("   -123");
    test_ft_atoi("\t\n  42");

    // Strings with leading plus/minus signs
    test_ft_atoi("+123");
    test_ft_atoi(" -42");

    // Overflow and underflow cases
    test_ft_atoi("2147483648");   // Exceeds INT_MAX
    test_ft_atoi("-2147483649");  // Exceeds INT_MIN

    // Invalid characters and mixed input
    test_ft_atoi("123abc");
    test_ft_atoi("42 is the answer");
    test_ft_atoi("   -56xyz");

    // Empty and non-numeric input
    test_ft_atoi("");
    test_ft_atoi("abc123");
}
/*                             isalpha                                     */

int ft_isalpha(int c);  // Declare your custom function

void test_isalpha(int c) {
    int expected = isalpha(c);   // Standard isalpha result
    int result = ft_isalpha(c);  // Custom ft_isalpha result

    // Compare both results as non-zero (true) or zero (false)
    if ((result != 0) == (expected != 0)) {
        printf("PASS: '%c' (ASCII %d) -> %d (ft_isalpha) == %d (isalpha)\n", 
               c, c, result, expected);
    } else {
        printf("FAIL: '%c' (ASCII %d) -> %d (ft_isalpha) != %d (isalpha)\n", 
               c, c, result, expected);
    }
}

void    isalpha_tests()
{
    // Test with all ASCII characters
    for (int c = CHAR_MIN; c <= CHAR_MAX; c++) {
        test_isalpha(c);
    }

    // Additional specific tests with boundary cases
    test_isalpha('A'); // Uppercase alphabetic character
    test_isalpha('Z'); // Uppercase alphabetic character
    test_isalpha('a'); // Lowercase alphabetic character
    test_isalpha('z'); // Lowercase alphabetic character
    test_isalpha('1'); // Non-alphabetic digit
    test_isalpha('@'); // Symbol
    test_isalpha('['); // Symbol just after uppercase letters
    test_isalpha('`'); // Symbol just before lowercase letters
    test_isalpha('{'); // Symbol just after lowercase letters
    test_isalpha(0);   // Null character
    test_isalpha(-1);  // Negative edge case
    test_isalpha(128); // Extended ASCII edge case (if applicable)
}
/*                             isdigit                                     */



// Prototype for ft_isdigit (your custom function)
int ft_isdigit(int c);

// Test function for isdigit and ft_isdigit
void test_isdigit() {
    char test_cases[] = {'0', '5', '9', 'a', 'Z', ' ', '!', '1', '3', '8'};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        char c = test_cases[i];
        int std_result = isdigit(c);
        int ft_result = ft_isdigit(c);
        
    int expected = isdigit(c);  
    int result = ft_isdigit(c); 

    // Compare both results as non-zero (true) or zero (false)
    if ((result != 0) == (expected != 0)) {
        printf("PASS: Testing character '%c': isdigit = %d, ft_isdigit = %d\n", c, std_result, ft_result);
    } else {
        printf("FAIL: Testing character '%c': isdigit = %d, ft_isdigit = %d\n", c, std_result, ft_result);
    }
    }

    
}

/*                               isalnum                                                */

// Prototype for ft_isalnum (your custom function)
int ft_isalnum(int c);

// Test function for isalnum and ft_isalnum
void test_isalnum() {
    char test_cases[] = {'0', '5', '9', 'a', 'Z', ' ', '!', '@', '1', 'k', 'B', '3', '?'};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int pass = 1; // Flag to indicate if all tests pass

    for (int i = 0; i < num_cases; i++) {
        char c = test_cases[i];
        int std_result = isalnum(c) != 0;  // Convert to 0 or 1 (true/false)
        int ft_result = ft_isalnum(c) != 0; // Convert to 0 or 1 (true/false)
        
        if (std_result != ft_result) {
            printf("FAIL: Character '%c' - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else    
            printf("PASS: Character '%c' - Expected %d, got %d\n", c, std_result, ft_result);
    }

    if (pass) {
        printf("PASS: All tests passed for ft_isalnum!\n");
    } else {
        printf("FAIL: Some tests failed for ft_isalnum.\n");
    }
}

// Prototype for ft_isascii (your custom function)
int ft_isascii(int c);

// Test function for isascii and ft_isascii
void test_isascii() {
    int test_cases[] = {0, 65, 127, 128, -1, 32, 100, 256}; // Variety of values in and out of ASCII range
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int pass = 1; // Flag to indicate if all tests pass

    for (int i = 0; i < num_cases; i++) {
        int c = test_cases[i];
        int std_result = isascii(c) != 0;    // Convert to 0 or 1 (true/false)
        int ft_result = ft_isascii(c) != 0;  // Convert to 0 or 1 (true/false)
        
        if (std_result != ft_result) {
            printf("FAIL: Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else
        printf("PASS: Character code %d - Expected %d, got %d\n", c, std_result, ft_result);

    }

    if (pass) {
        printf("PASS: All tests passed for ft_isascii!\n");
    } else {
        printf("FAIL: Some tests failed for ft_isascii.\n");
    }
}

// Prototype for ft_isprint (your custom function)
int ft_isprint(int c);

// Test function for isprint and ft_isprint
void test_isprint() {
    int test_cases[] = {31, 32, 48, 65, 97, 126, 127, -1, 0, 255}; // Variety of values in and out of printable range
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int pass = 1; // Flag to indicate if all tests pass

    for (int i = 0; i < num_cases; i++) {
        int c = test_cases[i];
        int std_result = isprint(c) != 0;    // Convert to 0 or 1 (true/false)
        int ft_result = ft_isprint(c) != 0;  // Convert to 0 or 1 (true/false)
        
        if (std_result != ft_result) {
            printf("FAIL: Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else 
            printf("FAIL: Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
    }

    if (pass) {
        printf("PASS: All tests passed for ft_isprint!\n");
    } else {
        printf("FAIL: Some tests failed for ft_isprint.\n");
    }
}

#include <string.h>

//size_t ft_strlen(const char *s);

void test_strlen(const char *test_str) {
    size_t std_len = strlen(test_str);
    size_t ft_len = ft_strlen(test_str);

    if (std_len == ft_len) {
        printf("PASS: '%s' | Expected: %zu, Got: %zu\n", test_str, std_len, ft_len);
    } else {
        printf("FAIL: '%s' | Expected: %zu, Got: %zu\n", test_str, std_len, ft_len);
    }
}

void tests_strlen() {
    test_strlen("Hello, world!");
    test_strlen("");
    test_strlen("A");
    test_strlen("   ");
    test_strlen("1234567890");
    test_strlen("!@#$%^&*()");
    test_strlen("This is a longer test string for strlen.");
    test_strlen("こんにちは"); // For multibyte characters, may need adjustments based on encoding
    test_strlen("hello\0world");

}

/*                  memset                      */


void print_buffer(const unsigned char *buf, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
}

void test_memset(unsigned char *buffer, size_t size, int c, size_t n) {
    // Copy buffer to compare original memset and ft_memset
    unsigned char buffer_std[size];
    unsigned char buffer_ft[size];
    memcpy(buffer_std, buffer, size);
    memcpy(buffer_ft, buffer, size);

    // Apply standard memset and ft_memset
    memset(buffer_std, c, n);
    ft_memset(buffer_ft, c, n);

    // Compare and print results
    if (memcmp(buffer_std, buffer_ft, size) == 0) {
        printf("PASS: ");
    } else {
        printf("FAIL: ");
    }
    printf("Set first %zu bytes to %d\n", n, c);
    printf("Expected: ");
    print_buffer(buffer_std, size);
    printf("Got:      ");
    print_buffer(buffer_ft, size);
}

int tests_memset() {
    unsigned char buffer1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    test_memset(buffer1, 10, 0, 5);  // Test Case 1

    unsigned char buffer2[5] = {1, 2, 3, 4, 5};
    test_memset(buffer2, 5, 'A', 3); // Test Case 2

    unsigned char buffer3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    test_memset(buffer3, 10, 1, 10); // Test Case 3

    unsigned char buffer4[6] = {0, 1, 2, 3, 4, 5};
    test_memset(buffer4, 6, 255, 4); // Test Case 4

    unsigned char buffer5[5] = {0, 0, 0, 0, 0};
    test_memset(buffer5, 5, 128, 5); // Test Case 5

    unsigned char buffer6[4] = {1, 2, 3, 4};
    test_memset(buffer6, 4, 77, 0);  // Test Case 6

    return 0;
}

int main() {

    printf("atoi TESTING START \n");
    atoi_tests();

    printf("isalpha TESTING START\n");
    isalpha_tests();

    printf("isdigit TESTING START\n");
    test_isdigit();

    printf("isalnum TESTING START\n");
    test_isalnum();

    printf("isascii TESTING START\n");
    test_isascii();

    printf("isprint TESTING START\n");
    test_isprint();

    printf("strlen TESTING START\n");
    tests_strlen();

    printf("memset TESTING START\n");
    test_memset_set()

    return 0;
}
