#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Caesar Cipher 

void caesar_encrypt(char *text, int shift) {
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (isupper((unsigned char)c))
            text[i] = (char)('A' + (c - 'A' + shift + 26) % 26);
        else if (islower((unsigned char)c))
            text[i] = (char)('a' + (c - 'a' + shift + 26) % 26);
    }
}

void caesar_decrypt(char *text, int shift) {
    caesar_encrypt(text, -shift);
}

// Vigenère Cipher 

void vigenere_encrypt(char *text, const char *key) {
    int keylen = strlen(key), j = 0;
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char k = key[j % keylen];
            int shift = (isupper((unsigned char)k) ? k - 'A' : k - 'a');
            if (isupper((unsigned char)c))
                text[i] = (char)('A' + (c - 'A' + shift) % 26);
            else
                text[i] = (char)('a' + (c - 'a' + shift) % 26);
            j++;
        }
    }
}

void vigenere_decrypt(char *text, const char *key) {
    int keylen = strlen(key), j = 0;
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char k = key[j % keylen];
            int shift = (isupper((unsigned char)k) ? k - 'A' : k - 'a');
            if (isupper((unsigned char)c))
                text[i] = (char)('A' + (c - 'A' - shift + 26) % 26);
            else
                text[i] = (char)('a' + (c - 'a' - shift + 26) % 26);
            j++;
        }
    }
}

// Utility

void read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin)) {
        size_t len = strlen(buffer);
        if (len && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
    }
}

// Main Program 

int main(void) {
    char choice[16], mode[16];
    char text[1024], key[128];
    int shift;
    int running = 1;

    printf("=== Simple Cryptography Tool ===\n");

    while (running) {
        printf("\nWould you like to encrypt, decrypt, or exit? (enc/dec/exit): ");
        read_line(choice, sizeof(choice));

        if (strcmp(choice, "exit") == 0) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }

        if (strcmp(choice, "enc") != 0 && strcmp(choice, "dec") != 0) {
            printf("Invalid choice! Please type 'enc', 'dec', or 'exit'.\n");
            continue;
        }

        printf("Choose cryptography method (caesar/vigenere): ");
        read_line(mode, sizeof(mode));

        printf("Enter your text: ");
        read_line(text, sizeof(text));

        if (strcmp(mode, "caesar") == 0) {
            printf("Enter shift (integer): ");
            scanf("%d", &shift);
            getchar(); // consume newline

            if (strcmp(choice, "enc") == 0) {
                caesar_encrypt(text, shift);
                printf("\nEncrypted text: %s\n", text);
            } else {
                caesar_decrypt(text, shift);
                printf("\nDecrypted text: %s\n", text);
            }
        }
        else if (strcmp(mode, "vigenere") == 0) {
            printf("Enter key (letters only): ");
            read_line(key, sizeof(key));

            if (strcmp(choice, "enc") == 0) {
                vigenere_encrypt(text, key);
                printf("\nEncrypted text: %s\n", text);
            } else {
                vigenere_decrypt(text, key);
                printf("\nDecrypted text: %s\n", text);
            }
        }
        else {
            printf("Invalid mode selected! Please choose 'caesar' or 'vigenere'.\n");
        }

        printf("\n-----------------------------------------\n");
    }

    return 0;
}
