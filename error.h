// this file will contain error handling definitions
#include <ostream>
#ifndef ERROR_H
#define ERROR_H
enum class ErrorCode {
    ANOTHER_FILE,
    DELETE_FAILED,
    SQRT_NEGATIVE,
    FILE_NOT_FOUND,
    DIVZERO,
    CANT_OPEN_FILE
};

inline std::ostream& operator<<(std::ostream& os, ErrorCode ec) {
    switch (ec) {
        case ErrorCode::ANOTHER_FILE:return os << "Another file with same name exists"; break;
        case ErrorCode::FILE_NOT_FOUND:return os << "File not found"; break;
        case ErrorCode::DELETE_FAILED:return os << "Delete file failed"; break;
        case ErrorCode::DIVZERO: return os << "Division by zero"; break;
        case ErrorCode::CANT_OPEN_FILE: return os << "Cannot open file";break;
        case ErrorCode::SQRT_NEGATIVE: return os << "Square root of negative number";break;
        default: return os << "Unknown error";
    }
}
#endif 