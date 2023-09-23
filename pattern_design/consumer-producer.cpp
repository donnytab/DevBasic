#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;
std::queue<int> buffer;   // shared buffer
constexpr int b_size = 10;
static int count = 8;

void producer() {
    std::unique_lock<std::mutex> lock(mtx);
    while (buffer.size() >= b_size) {      // buffer full, wait for consumer to consume
        cv_producer.wait(lock);
    }
    buffer.push(count++);
    std::cout << "producer: " << i << std::endl;

    cv_consumer.notify_one();    // notify consumer
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    while (buffer.empty()) {
        cv_consumer.wait(lock);
    }

    int data = buffer.front();
    buffer.pop();
    std::cout << "consumer: " << data << std::endl;

    cv_producer.notify_one()    // notify producer
}

int main() {
    std::thread producer_t(producer);
    std::thread consumer_t(consumer);

    producer_t.join();
    consumer_t.join();

    return 0;
}
