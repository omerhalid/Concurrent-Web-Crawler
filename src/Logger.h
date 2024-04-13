#include <fstream>
#include <string>

class Logger {
    std::ofstream log_file;
public:
    Logger(const std::string& filename);
    void log(const std::string& message);
};
