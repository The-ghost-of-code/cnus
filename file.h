#include "printk.h"
#include <filesystem>
#include <cstdlib>
#include "define.h"

bool fileEx(const std::filesystem::path& path) {
    return std::filesystem::exists(path);
}

void file_is_exist(const std::filesystem::path& path) {
    if (fileEx(path)) {
        printk("File exists\n");
    } else {
        printk(to_string(ErrorCode::FILE_NOT_FOUND));
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