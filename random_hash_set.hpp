#pragma once
#include <unordered_set>
#include <random>
class random_hash_set {
private:
    std::unordered_set<int>vals_;
public:
    bool insert(int val) {
        if (vals_.find(val) != vals_.end()) {
            return false;
        }
        vals_.insert(val);
        return true;
    }
    bool remove(int val) {
        auto it = vals_.find(val);
        if (vals_.end() == it) {
            return false;
        }
        vals_.erase(val);
        return true;
    }
    int get_random() {
        std::random_device rd;  
        std::mt19937 gen(rd());  
        std::uniform_int_distribution<> dis(0, vals_.size() - 1);  
        int index = dis(gen);
        auto it = vals_.begin();
        for (int i = 0;i < index;i++) {
            ++it;
        }
        return *it;
    }
    inline int get_size() const {
        return vals_.size();
    }
};