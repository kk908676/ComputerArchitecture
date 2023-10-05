#include <stdio.h>
#include <stdint.h>

/* Counting leading zeros function */
uint16_t count_leading_zeros(uint64_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);

    /* Count ones (population count) */
    x -= ((x >> 1) & 0x5555555555555555);
    x = ((x >> 2) & 0x3333333333333333) + (x & 0x3333333333333333);
    x = ((x >> 4) + x) & 0x0f0f0f0f0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);

    return (64 - (x & 0x7f));
}

/* Simple XOR-based encryption function with leading zero count */
void encrypt(uint64_t *data, uint64_t key)
{
    uint16_t leading_zeros = count_leading_zeros(key);
    *data ^= (key << leading_zeros);
}

/* Simple XOR-based decryption function with leading zero count */
void decrypt(uint64_t *data, uint64_t key)
{
    uint16_t leading_zeros = count_leading_zeros(key);
    *data ^= (key << leading_zeros);
}

int main()
{
    uint64_t key = 0x0123456789ABCDEF; // Encryption key
    uint64_t test_data = 0x0000000010101010; // Test data in binary

    printf("Original Data:\n");
    printf("Data: 0x%016lx\n", test_data);

    /* Encrypt and print encrypted data */
    printf("\nEncrypted Data:\n");
    encrypt(&test_data, key);
    printf("Data: 0x%016lx\n", test_data);

    /* Decrypt and print decrypted data */
    printf("\nDecrypted Data:\n");
    decrypt(&test_data, key);
    printf("Data: 0x%016lx\n", test_data);

    return 0;
}
