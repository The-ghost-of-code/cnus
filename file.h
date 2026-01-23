#include "printk.h"
#include <filesystem>
#include <cstdlib>
#include "define.h"
#include "error.h"

bool fileEx(const std::filesystem::path& path) {
    return std::filesystem::exists(path);
}

void file_is_exist(const std::filesystem::path& path) {
    if (fileEx(path)) {
        printk("File exists\n");
    } else {
        printk(ErrorCode::FILE_NOT_FOUND);
    }
}

void file_open(const std::filesystem::path& path) {
    if (get_os_name() == "Windows") {
        system(("start " + path.string()).c_str());
    }
    else if (get_os_name() == "Linux" || get_os_name() == "macOS" || get_os_name() == "Unix") {
        system(("xdg-open " + path.string()).c_str());
    }
    else {
        printk("Unsupported OS for opening files\n");
    }
}

double file_size(const std::filesystem::path& path, const char * convert_to = "KB") {
    if (!fileEx(path)) {
        printk(ErrorCode::FILE_NOT_FOUND);
        return -2.0;
    }
    auto size_in_bytes = std::filesystem::file_size(path);
    if (size_in_bytes == static_cast<uintmax_t>(-1)) {
        printk(ErrorCode::CANT_OPEN_FILE);
        return -1.0;
    }
    if (convert_to == "B") {
        return static_cast<double>(size_in_bytes);
    }
    if (convert_to == "KB") {
        return static_cast<double>(size_in_bytes) / 1024.0;
    }
    if (convert_to == "MB") {
        return static_cast<double>(size_in_bytes) / (1024 * 1024);
    }
    if (convert_to == "GB") {
        return static_cast<double>(size_in_bytes) / (1024 * 1024 * 1024);
    }
    return 0.0;
}

void file_delete(const std::filesystem::path& path) {
    if (!fileEx(path)) {
        printk(ErrorCode::FILE_NOT_FOUND);
        return;
    }
    try {
        std::filesystem::remove(path);
        printk("File deleted successfully");
    } catch (const std::filesystem::filesystem_error& e) {
        printk(ErrorCode::DELETE_FAILED);
        printk(e.what());
        return;
    }
}
void copy_file(const std::filesystem::path& from, const std::filesystem::path& to) {
    if (!fileEx(from)) {
        printk(ErrorCode::FILE_NOT_FOUND);
        return;
    }
    if (fileEx(to)) {
        printk("Are you sure you want to overwrite the existing file? (y/n)");
        char response;
        std::cin >> response;
        if (response != 'y' && response != 'Y') {
            printk(ErrorCode::ANOTHER_FILE);
            return;
        }
        else {
            try {
                std::filesystem::copy(from, to, std::filesystem::copy_options::overwrite_existing);
            } catch (const std::filesystem::filesystem_error& e) {
                printk(ErrorCode::CANT_OPEN_FILE);
                printk(e.what());
            }
            printk("File copied and overwritten successfully");
        }
    }
    else {
        try {
            auto parent_path = to.parent_path();
            if (!parent_path.empty()) {
                std::filesystem::create_directories(parent_path);
            }
            std::filesystem::copy(from, to, std::filesystem::copy_options::overwrite_existing);
        } catch (const std::filesystem::filesystem_error& e) {
            printk(ErrorCode::CANT_OPEN_FILE);
            printk(e.what());
        }
        printk("File copied successfully");
    }
}