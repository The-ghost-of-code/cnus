// this file will contain error handling definitions
#ifndef ERROR_H
#define ERROR_H
enum class ErrorCode {
    OUT_OF_MEMORY,
    NONE,
    INVALID_PARAMETER,
    FILE_NOT_FOUND,
    DIVZERO,
    CANT_OPEN_FILE
};
#endif // ERROR_H

inline constexpr const char* to_string(ErrorCode ec) {
    switch (ec) {
        case ErrorCode::NONE: return "No error";
        case ErrorCode::INVALID_PARAMETER: return "Invalid parameter";
        case ErrorCode::OUT_OF_MEMORY: return "Out of memory";
        case ErrorCode::FILE_NOT_FOUND: return "File not found";
        case ErrorCode::DIVZERO: return "Division by zero";
        case ErrorCode::CANT_OPEN_FILE: return "Cannot open file";
        default: return "Unknown error";
    }
}