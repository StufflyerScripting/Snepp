#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inFile("compilefile.snapp");
    std::stringstream buffer;

    if (!inFile) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    buffer << inFile.rdbuf();  // Read entire file into buffer
    inFile.close();

    std::string content = buffer.str();
    std::string from = "var ";
    std::string to = "";
    std::string from1 = "v_";
    std::string to1 = "v";
    std::string from2 = "system.";
    std::string to2 = "sys";
    std::string from3 = " = nil";
    std::string to3 = "";


    // Replace all occurrences
    size_t pos = 0;
    while ((pos = content.find(from, pos)) != std::string::npos) {
        content.replace(pos, from.length(), to);
        pos += to.length();
    }
    pos = 0;
    while ((pos = content.find(from1, pos)) != std::string::npos) {
        content.replace(pos, from1.length(), to1);
        pos += to1.length();
    }
    pos = 0;
    while ((pos = content.find(from2, pos)) != std::string::npos) {
        content.replace(pos, from2.length(), to2);
        pos += to2.length();
    }
    pos = 0;
    while ((pos = content.find(from3, pos)) != std::string::npos) {
        content.replace(pos, from3.length(), to3);
        pos += to3.length();
    }

    std::ofstream outFile("compiledfile.snas");  // Overwrite file
    outFile << content;
    outFile.close();

    std::cout << "File updated successfully.\n";
    return 0;
}
