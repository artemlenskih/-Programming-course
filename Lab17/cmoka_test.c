#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "Misha_test.c"

static void test_1(void **state) {
    char text[] = "Hello World";
    char key[] = "secret";
    char output[20];
    char decrypted[20];
    xor_encrypt(text, key, output, strlen(text));
    xor_encrypt(output, key, decrypted, strlen(text));
    assert_string_equal(text, decrypted);

}
static void test_2(void **state) {
    char text[] = "qwertyuiopasdfghjklzxcvbnm";
    char output[50];
    char decrypted[50];
    caesar_cipher(text, 3, output);
    caesar_cipher(output, -3, decrypted);
    assert_string_equal(text, decrypted);
}
static void test_3(void **state) {
    char key[] = "Key";
    char original[] = "Secret message";
    char data[100];
    int data_len = strlen(original);
    strcpy(data, original);
    simple_rc4(key, strlen(key), data, data_len);
    simple_rc4(key, strlen(key), data, data_len);
    assert_string_equal(original, data);
}
int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_1),
        cmocka_unit_test(test_2),
        cmocka_unit_test(test_3),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}