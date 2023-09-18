#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>

class AESKeyManager {
private:
    // Assuming AES keys are represented as strings for simplicity.
    std::vector<std::string> keys;
    std::set<std::string> usedKeys;

    // Random number generator
    std::random_device rd;
    std::mt19937 g;

public:
    AESKeyManager() : g(rd()) {}

    // Add a new key to the library
    void addKey(const std::string& key) {
        if (usedKeys.find(key) == usedKeys.end()) {
            keys.push_back(key);
        }
    }

    // Sort the keys
    void sortKeys() {
        std::sort(keys.begin(), keys.end());
    }

    // Randomize the order of the keys
    void randomizeKeys() {
        std::shuffle(keys.begin(), keys.end(), g);
    }

    // Get the next key. This will mark the key as used and remove it from the list.
    std::string getNextKey() {
        if (keys.empty()) {
            throw std::runtime_error("No more keys available");
        }

        std::string key = keys.back();
        keys.pop_back();
        usedKeys.insert(key);
        return key;
    }

    // Check if a key has been used
    bool isKeyUsed(const std::string& key) const {
        return usedKeys.find(key) != usedKeys.end();
    }

    // Print all available keys
    void printKeys() const {
        for (const auto& key : keys) {
            std::cout << key << std::endl;
        }
    }
};

int main() {
    AESKeyManager manager;
    manager.addKey("key1");
    manager.addKey("key2");
    manager.addKey("key3");

    manager.sortKeys();
    manager.printKeys();

    std::cout << "Randomizing keys..." << std::endl;
    manager.randomizeKeys();
    manager.printKeys();

    std::cout << "Fetching a key..." << std::endl;
    std::string key = manager.getNextKey();
    std::cout << "Fetched key: " << key << std::endl;

    if (manager.isKeyUsed(key)) {
        std::cout << key << " has been used." << std::endl;
    }

    return 0;
}
