#include <mutex>
#include <iostream>

std::mutex ls_mutex;

class HungrySingleton {
public:
    static HungrySingleton* getInstance() {
        return hs_singleton;
    }
    ~HungrySingleton(){}

private:
    static HungrySingleton* hs_singleton;
    HungrySingleton(){};
    HungrySingleton(const HungrySingleton& hs){}
    HungrySingleton& operator=(const HungrySingleton& hs){ return *this; }
};

class LazySingleton {
public:
    static LazySingleton* getInstance() {
        const std::lock_guard<std::mutex> lock(ls_mutex);
        if (ls_singleton == nullptr) {
            ls_singleton = new LazySingleton();
        }
        return ls_singleton;
    }
    ~LazySingleton(){}

private:
    static LazySingleton* ls_singleton;
    LazySingleton(){};
    LazySingleton(const LazySingleton& ls){}
    LazySingleton& operator=(const LazySingleton& hs){ return *this; }
};

HungrySingleton* HungrySingleton::hs_singleton = new HungrySingleton();
LazySingleton* LazySingleton::ls_singleton = nullptr;

int main() {
    auto singleton1 = HungrySingleton::getInstance();
    auto singleton2 = LazySingleton::getInstance();
    return 0;
}
