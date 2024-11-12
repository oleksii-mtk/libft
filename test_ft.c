#include <stdio.h>
#include <stdlib.h> // for atoi
#include <ctype.h>  // for the standard isalpha
#include <limits.h> // for INT_MAX and INT_MIN
#include "libft.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

/*                             atoi                                     */

int ft_atoi(const char *str);  // Declare your function from libft.a

void test_ft_atoi(const char *str) {
    int expected = atoi(str);   // Standard atoi result
    int result = ft_atoi(str);  // Custom ft_atoi result from libft.a

    if (result == expected) {
        printf(GREEN "PASS" RESET ": \"%s\" -> %d (ft_atoi) == %d (atoi)\n", str, result, expected);
    } else {
        printf(RED "FAIL" RESET ": \"%s\" -> %d (ft_atoi) != %d (atoi)\n", str, result, expected);
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
        printf(GREEN "PASS" RESET ": '%c' (ASCII %d) -> %d (ft_isalpha) == %d (isalpha)\n", 
               c, c, result, expected);
    } else {
        printf(RED "FAIL" RESET ": '%c' (ASCII %d) -> %d (ft_isalpha) != %d (isalpha)\n", 
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
        printf(GREEN "PASS" RESET ": Testing character '%c': isdigit = %d, ft_isdigit = %d\n", c, std_result, ft_result);
    } else {
        printf(RED "FAIL" RESET ": Testing character '%c': isdigit = %d, ft_isdigit = %d\n", c, std_result, ft_result);
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
            printf(RED "FAIL" RESET ": Character '%c' - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else    
            printf(GREEN "PASS" RESET ": Character '%c' - Expected %d, got %d\n", c, std_result, ft_result);
    }

    if (pass) {
        printf(GREEN "PASS" RESET ": All tests passed for ft_isalnum!\n");
    } else {
        printf(RED "FAIL" RESET ": Some tests failed for ft_isalnum.\n");
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
            printf(RED "FAIL" RESET ": Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else
        printf(GREEN "PASS" RESET ": Character code %d - Expected %d, got %d\n", c, std_result, ft_result);

    }

    if (pass) {
        printf(GREEN "PASS" RESET ": All tests passed for ft_isascii!\n");
    } else {
        printf(RED "FAIL" RESET ": Some tests failed for ft_isascii.\n");
    }
}


// Test function for isprint and ft_isprint
void test_isprint() {
    int test_cases[] = {31, 32, 48, 65, 97, 126, 127, 128, -1, 0, 255}; // Variety of values in and out of printable range
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int pass = 1; // Flag to indicate if all tests pass

    for (int i = 0; i < num_cases; i++) {
        int c = test_cases[i];
        int std_result = isprint(c) > 0;    // Convert to 0 or 1 (true/false)
        int ft_result = ft_isprint(c) > 0;  // Convert to 0 or 1 (true/false)
        
        if (std_result != ft_result) {
            printf(RED "FAIL" RESET ": Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
            pass = 0; // Mark as fail if any test fails
        }
        else 
            printf(GREEN "PASS" RESET ": Character code %d - Expected %d, got %d\n", c, std_result, ft_result);
    }

}

#include <string.h>

//size_t ft_strlen(const char *s);

void test_strlen(const char *test_str) {
    size_t std_len = strlen(test_str);
    size_t ft_len = ft_strlen(test_str);

    if (std_len == ft_len) {
        printf(GREEN "PASS" RESET ": '%s' | Expected: %zu, Got: %zu\n", test_str, std_len, ft_len);
    } else {
        printf(RED "FAIL" RESET ": '%s' | Expected: %zu, Got: %zu\n", test_str, std_len, ft_len);
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
        printf(GREEN "PASS" RESET ": ");
    } else {
        printf(RED "FAIL" RESET ": ");
    }
    printf("Set first %zu bytes to %d\n", n, c);
    printf("Expected: ");
    print_buffer(buffer_std, size);
    printf("Got:      ");
    print_buffer(buffer_ft, size);
}

void tests_memset() {
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

}

void test_bzero(unsigned char *buffer, size_t size, size_t n) {
    // Copy buffer to compare bzero and ft_bzero
    unsigned char buffer_std[size];
    unsigned char buffer_ft[size];
    memcpy(buffer_std, buffer, size);
    memcpy(buffer_ft, buffer, size);

    // Apply standard bzero and ft_bzero
    bzero(buffer_std, n);
    ft_bzero(buffer_ft, n);

    // Compare and print results
    if (memcmp(buffer_std, buffer_ft, size) == 0) {
        printf("\033[32mPASS\033[0m: ");
    } else {
        printf("\033[31mFAIL\033[0m: ");
    }
    printf("Zero first %zu bytes\n", n);
    printf("Expected: ");
    print_buffer(buffer_std, size);
    printf("Got:      ");
    print_buffer(buffer_ft, size);
}

void tests_bzero() {
    unsigned char buffer1[5] = {1, 2, 3, 4, 5};
    test_bzero(buffer1, 5, 5);  // Test Case 1

    unsigned char buffer2[5] = {1, 2, 3, 4, 5};
    test_bzero(buffer2, 5, 3);  // Test Case 2

    unsigned char buffer3[4] = {1, 2, 3, 4};
    test_bzero(buffer3, 4, 0);  // Test Case 3

    unsigned char buffer4[0] = {}; // Empty array
    test_bzero(buffer4, 0, 0);     // Test Case 4

    unsigned char buffer5[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    test_bzero(buffer5, 10, 10);   // Test Case 5

    unsigned char buffer6[5] = {'\n', '\t', '@', '!', '#'};
    test_bzero(buffer6, 5, 5);     // Test Case 6

}


void test_memcpy(unsigned char *dest, const unsigned char *src, size_t size, size_t n) {
    // Copy src to two separate destination arrays for testing
    unsigned char dest_std[size];
    unsigned char dest_ft[size];
    memcpy(dest_std, dest, size);
    memcpy(dest_ft, dest, size);

    // Apply standard memcpy and ft_memcpy
    memcpy(dest_std, src, n);
    ft_memcpy(dest_ft, src, n);

    // Compare and print results
    if (memcmp(dest_std, dest_ft, size) == 0) {
        printf("\033[32mPASS\033[0m: ");
    } else {
        printf("\033[31mFAIL\033[0m: ");
    }
    printf("Copy %zu bytes\n", n);
    printf("Expected: ");
    print_buffer(dest_std, size);
    printf("Got:      ");
    print_buffer(dest_ft, size);
}

int tests_memcpy() {
    unsigned char dest1[5] = {0, 0, 0, 0, 0};
    unsigned char src1[5] = {1, 2, 3, 4, 5};
    test_memcpy(dest1, src1, 5, 5);  // Test Case 1

    unsigned char dest2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned char src2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_memcpy(dest2, src2, 10, 5);  // Test Case 2

    unsigned char dest3[5] = {1, 2, 3, 4, 5};
    unsigned char src3[5] = {9, 8, 7, 6, 5};
    test_memcpy(dest3, src3, 5, 0);   // Test Case 3

    unsigned char dest4[5];
    unsigned char src4[5] = {1, 1, 1, 1, 1};
    test_memcpy(dest4, src4, 5, 5);   // Test Case 4

    // Overlapping memory cases
    unsigned char buffer5[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_memcpy(buffer5 + 2, buffer5, 10, 5);  // Test Case 5 (undefined behavior)

    unsigned char buffer6[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test_memcpy(buffer6, buffer6 + 2, 10, 5);  // Test Case 6 (undefined behavior)

    unsigned char dest7[100] = {0};
    unsigned char src7[100];
    for (size_t i = 0; i < 100; i++) src7[i] = i;
    test_memcpy(dest7, src7, 100, 100);  // Test Case 7

    return 0;
}

void compare_memmove(const char *description, char *dest, const char *src, size_t n) {
    // Allocate separate memory for dest buffers to avoid overlap issues during comparison
    char *dest1 = malloc(n + 1);  // For standard memmove
    char *dest2 = malloc(n + 1);  // For ft_memmove

    if (!dest1 || !dest2) {
        perror("Failed to allocate memory");
        free(dest1);
        free(dest2);
        return;
    }

    // Initialize both destination buffers with the same content
    strncpy(dest1, dest, n);
    strncpy(dest2, dest, n);
    dest1[n] = '\0';
    dest2[n] = '\0';

    // Run both memmove and ft_memmove
    memmove(dest1, src, n);
    ft_memmove(dest2, src, n);

    // Compare results
    if (strcmp(dest1, dest2) == 0) {
        printf("\033[32mPASS\033[0m %s\n", description);
    } else {
        printf("\033[31mFAIL\033[0m %s\n", description);
        printf("memmove result   : %s\n", dest1);
        printf("ft_memmove result: %s\n", dest2);
    }

    free(dest1);  // Free allocated buffers
    free(dest2);
}

int tests_memmove() {
    // Test 1: Basic Copy Test
    char dest1[20];
    compare_memmove("Basic Copy Test", dest1, "Hello, World!", 13);

    // Test 2: Forward Overlapping Copy Test
    char data2[] = "Overlapping Test";
    compare_memmove("Forward Overlapping Copy Test", data2 + 5, data2, strlen(data2) + 1);

    // Test 3: Backward Overlapping Copy Test
    char data3[] = "Overlapping Test";
    compare_memmove("Backward Overlapping Copy Test", data3, data3 + 5, strlen(data3) - 5 + 1);

    // Test 4: Zero-Length Copy Test
    char data4[] = "No effect";
    compare_memmove("Zero-Length Copy Test", data4 + 3, data4, 0);

    // Test 5: Partial Copy Test
    char dest5[20] = {0};
    compare_memmove("Partial Copy Test", dest5, "Partial Copy", 7);

    // Test 6: Self-Copy Test
    char data6[] = "Self-copy";
    compare_memmove("Self-Copy Test", data6, data6, strlen(data6) + 1);

    return 0;
}


// Helper function to test strlcpy and ft_strlcpy
void test_strlcpy(const char *description, char *dest1, char *dest2, const char *src, size_t size) {
    size_t len1 = strlcpy(dest1, src, size);
    size_t len2 = ft_strlcpy(dest2, src, size);

    printf("%s:\n", description);
    printf("Source      : \"%s\"\n", src);
    printf("Destination : \"%s\" (strlcpy), \"%s\" (ft_strlcpy)\n", dest1, dest2);
    printf("Return value: %zu (strlcpy), %zu (ft_strlcpy)\n", len1, len2);
    
    if (strcmp(dest1, dest2) == 0 && len1 == len2) {
        printf("Result      : Passed\n\n");
    } else {
        printf("Result      : Failed\n\n");
    }
}

int tests_strlcpy() {
    char dest1[20];
    char dest2[20];

    // Test 1: Basic Copy Test
    test_strlcpy("Basic Copy Test", dest1, dest2, "Hello, World!", 20);

    // Test 2: Exact Fit Test (size equals src length + 1)
    test_strlcpy("Exact Fit Test", dest1, dest2, "ExactFit", 9);

    // Test 3: Buffer Too Small Test (truncated copy)
    test_strlcpy("Buffer Too Small Test", dest1, dest2, "This is a long string", 10);

    // Test 4: Buffer Size Zero Test (no copy should happen)
    test_strlcpy("Buffer Size Zero Test", dest1, dest2, "NoCopy", 0);

    // Test 5: Empty Source String Test
    test_strlcpy("Empty Source String Test", dest1, dest2, "", 10);

    // Test 6: Large Size with Small Source
    test_strlcpy("Large Size with Small Source", dest1, dest2, "Small", 50);

    // Test 7: Destination Buffer Too Small for Even Null Character
    char small_dest1[1] = {'X'};
    char small_dest2[1] = {'X'};
    test_strlcpy("Dest Too Small for Null", small_dest1, small_dest2, "Can't fit", 1);

    return 0;
}

void print_test_result(int passed, const char *description) {
    if (passed) {
        printf("\033[32mPASS\033[0m %s\n", description);  // Зеленый для PASS
    } else {
        printf("\033[31mFAIL\033[0m %s\n", description);  // Красный для FAIL
    }
}

void test_ft_strlcat()
{
    char dst[50];
    const char *src = "World";
    size_t result;

    // Case A: Empty dst, non-empty src
    strcpy(dst, "");
    result = ft_strlcat(dst, src, 50);
    print_test_result(strcmp(dst, "World") == 0 && result == strlen(src), "Empty dst, non-empty src");

    // Case B: Non-empty dst, empty src
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, "", 50);
    print_test_result(strcmp(dst, "Hello") == 0 && result == strlen("Hello"), "Non-empty dst, empty src");

    // Case C: Both empty
    strcpy(dst, "");
    result = ft_strlcat(dst, "", 50);
    print_test_result(strcmp(dst, "") == 0 && result == 0, "Both empty");

    // Case D: size less than dst length
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 3);
    print_test_result(result == 3 + strlen(src) && strcmp(dst, "Hello") == 0, "size < dst length");

    // Case E: size equal to dst length
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 5);
    print_test_result(result == strlen("Hello") + strlen("World") && strcmp(dst, "Hello") == 0, "size == dst length");

    // Case F: size > dst length, enough for src
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 50);
    print_test_result(strcmp(dst, "HelloWorld") == 0 && result == strlen("HelloWorld"), "size > dst length, enough for src");

    // Case G: size < dst + src length
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 8);
    print_test_result(result == strlen("Hello") + strlen("World") && strcmp(dst, "HelloWo") == 0, "size < dst + src length");

    // Case H: size == 0
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 0);
    print_test_result(result == strlen("Hello") + strlen("World") && strcmp(dst, "Hello") == 0, "size == 0");

    // Case I: size == 1
    strcpy(dst, "Hello");
    result = ft_strlcat(dst, src, 1);
    print_test_result(result == strlen("Hello") + strlen("World") && strcmp(dst, "Hello") == 0, "size == 1");
    printf("%u, -%u -%lu", strlen(dst),strlen(src), strlen(result));
}



void test_ft_itoa(int n, const char *expected_result) {
    char *result = ft_itoa(n);
    if (strcmp(result, expected_result) == 0) {
        printf("Test passed for input %d\n", n);
    } else {
        printf("Test failed for input %d\n", n);
        printf("Expected: %s, Got: %s\n", expected_result, result);
    }
    free(result);
}

int tests_itoa() {
    // Тест 1: Число 0
    test_ft_itoa(0, "0");

    // Тест 2: Положительное число
    test_ft_itoa(12345, "12345");

    // Тест 3: Отрицательное число
    test_ft_itoa(-12345, "-12345");

    // Тест 4: INT_MAX
    test_ft_itoa(INT_MAX, "2147483647");

    // Тест 5: INT_MIN
    test_ft_itoa(INT_MIN, "-2147483648");

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
    tests_memset();

    printf("bzero TESTING START\n");
    tests_bzero();

    printf("memcpy TESTING START\n");
    tests_memcpy();

    printf("memmove TESTING START\n");
    tests_memmove();

    printf("strlcpy TESTING START\n");
    tests_strlcpy();

    printf("strlcut TESTING START\n");
    test_ft_strlcat();

    printf("itoa TESTING START\n");
    tests_itoa();

    return 0;
}
