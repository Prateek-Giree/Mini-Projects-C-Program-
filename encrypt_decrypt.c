// Data encryption/decryption. Caesar chipher implementation
// shift value by 4 i.e a = d
// #include <stdio.h>
// void encrypt();
// void decrypt();
// void main()
// {
//     encrypt();
//     decrypt();
// }

// void encrypt()
// {
//     char message[100];
//     int i;
//     printf("Enter a message: ");
//     gets(message);

//}
#include <stdio.h>

int main()
{
    char message[100];
    int shift, i;
    printf("Enter message: ");
    fgets(message, 100, stdin);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encryption
    for (i = 0; message[i] != '\0'; ++i)
    {
        char c = message[i];
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + (c - 'a' + shift) % 26;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + (c - 'A' + shift) % 26;
        }
        message[i] = c;
    }

    printf("Encrypted message: %s", message);

    // Decryption
    for (i = 0; message[i] != '\0'; ++i)
    {
        char c = message[i];
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + (c - 'a' - shift + 26) % 26;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + (c - 'A' - shift + 26) % 26;
        }
        message[i] = c;
    }

    printf("Decrypted message: %s", message);

    return 0;
}
