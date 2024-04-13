#include "URLFrontier.h"

void URLFrontier::addURL(const std::string& url) {
    std::lock_guard<std::mutex> guard(queue_mutex); // Locks the mutex, and unlocks it when out of scope
    url_queue.push_back(url);
}

std::string URLFrontier::getNextURL()
{
    std::lock_guard<std::mutex> guard(queue_mutex);

    if(!url_queue.empty())
    {
        std::string url = url_queue.front();
        url_queue.pop_front();
        return url;
    }

    return ""; /// if URLs are available
}

bool URLFrontier::isEmpty() const
{
    std::lock_guard<std::mutex> guard(queue_mutex);
    return url_queue.empty();
}