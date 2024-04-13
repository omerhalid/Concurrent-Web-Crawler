#include <deque>
#include <string>
#include <mutex>

class URLFrontier {
    std::deque<std::string> url_queue;
    std::mutex queue_mutex;

public:
    void addURL(const std::string& url);
    std::string getNextURL();
    bool isEmpty() const;
};
