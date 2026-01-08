// this file will contain error handling definitions
#ifndef ERROR_H
#define ERROR_H
enum class ErrorCode {
    OUT_OF_MEMORY,
    DELETE_FAILED,
    INVALID_PARAMETER,
    FILE_NOT_FOUND,
    DIVZERO,
    CANT_OPEN_FILE
};
#endif // ERROR_H

inline std::ostream& operator<<(std::ostream& os, ErrorCode ec) {
    switch (ec) {
        case ErrorCode::INVALID_PARAMETER:return os << "Invalid parameter"; break;
        case ErrorCode::OUT_OF_MEMORY:return os << "Out of memory"; break;
        case ErrorCode::FILE_NOT_FOUND:return os << "File not found"; break;
        case ErrorCode::DELETE_FAILED:return os << "Delete file failed"; break;
        case ErrorCode::DIVZERO: return os << "Division by zero";
        case ErrorCode::CANT_OPEN_FILE: return os << "Cannot open file";
        default: return os << "Unknown error";
    }
}