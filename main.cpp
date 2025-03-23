#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <binary_filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string searchString = "gconnect.ubi.com";
    std::ifstream inputFile(filename, std::ios::binary);

    if (!inputFile) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    std::string fileContent(buffer.begin(), buffer.end());

    size_t pos = 0;
    bool found = false;
    while ((pos = fileContent.find(searchString, pos)) != std::string::npos) {
        if (!found) {
            std::string backupFilename = filename + ".bak";
            try {
                std::filesystem::copy_file(filename, backupFilename, std::filesystem::copy_options::overwrite_existing);
                std::cout << "Backup created as \"" << backupFilename << "\"." << std::endl;
            } catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Error: Could not create backup file " << backupFilename << ": " << e.what() << std::endl;
                return 1;
            }
            found = true;
        }
        std::fill(fileContent.begin() + pos, fileContent.begin() + pos + searchString.size(), '\0');
        pos += searchString.size();
    }

    if (!found) {
        std::cout << "No occurrences of \"" << searchString << "\" were found. No changes made." << std::endl;
        return 0;
    }

    std::ofstream outputFile(filename, std::ios::binary | std::ios::trunc);
    if (!outputFile) {
        std::cerr << "Error: Could not open the file " << filename << " for writing" << std::endl;
        return 1;
    }

    outputFile.write(fileContent.data(), fileContent.size());
    outputFile.close();

    std::cout << "All occurrences of \"" << searchString << "\" have been replaced with 0x00 bytes." << std::endl;
    return 0;
}