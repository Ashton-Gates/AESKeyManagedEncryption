# AES Encryption Library with Key Management
This library randomizes AES keys
This library provides AES encryption and decryption functionality with integrated key management. It ensures that each AES key is used only once for encryption.

# Features
AES encryption and decryption using OpenSSL.
Key management to ensure each key is used only once.
Ability to sort, randomize, and retrieve AES keys.
Encrypted data is returned as a byte array for better security.
# Prerequisites
OpenSSL development libraries
For Debian/Ubuntu:

sudo apt-get install libssl-dev

For Red Hat/Fedora:

sudo yum install openssl-devel

# Usage
Initialize the AESKeyManager:

AESKeyManager manager;
manager.addKey("key1");
manager.addKey("key2");
manager.addKey("key3");

Use the AESEncryption class for encryption and decryption:

AESEncryption aes(manager);

std::string plaintext = "Hello, World!";
std::vector<unsigned char> encrypted = aes.encrypt(plaintext);
std::string decrypted = aes.decrypt(encrypted, "key1");
Note: For demonstration purposes, the same key is used for decryption in the example. In a real-world scenario, you'd manage keys differently.

# Compilation
To compile the program, use:

g++ -o aes_program your_filename.cpp -lcrypto

# License
This project is open-source and available under the MIT License.

