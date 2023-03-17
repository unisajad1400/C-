#include <openssl/aes.h>
#include <iostream>
#include <cstring>

int main() {
    unsigned char key[] = "0123456789abcdef";
    unsigned char iv[] = "fedcba9876543210";
    const char* message = "Hello, world!";

    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    size_t messageLen = strlen(message);
    size_t paddedLen = ((messageLen + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char* paddedMessage = new unsigned char[paddedLen];
    memcpy(paddedMessage, message, messageLen);
    memset(paddedMessage + messageLen, paddedLen - messageLen, paddedLen - messageLen);

    unsigned char* encryptedMessage = new unsigned char[paddedLen];
    AES_cbc_encrypt(paddedMessage, encryptedMessage, paddedLen, &aesKey, iv, AES_ENCRYPT);

    std::cout << "Original message: " << message << std::endl;
    std::cout << "Encrypted message: ";
    for (size_t i = 0; i < paddedLen; ++i) {
        std::cout << std::hex << (int)encryptedMessage[i];
    }
    std::cout << std::dec << std::endl;

    delete[] paddedMessage;
    delete[] encryptedMessage;

    return 0;
}

// cmake -S . -B build
// cmake --build build