#include <stdio.h>
#include <stdlib.h> // for atoi
#include <ctype.h>  // for the standard isalpha
#include <limits.h> // for INT_MAX and INT_MIN


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




int main() {

    printf("atoi TESTING START \n");
    atoi_tests();
    printf("isalpha TESTING START\n");
    isalpha_tests();

    return 0;
}
