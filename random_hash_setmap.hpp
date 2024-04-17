#pragma once
#include <vector>
#include <unordered_map>
#include <random>
class random_hash_setmap {
private:
    std::unordered_map<int, int>val_index_;
    std::vector<int>vals_;
public:
    bool insert(int val) {
        if (val_index_.find(val) != val_index_.end()) {
            return false;
        }
        val_index_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    bool remove(int val) {
        auto it = val_index_.find(val);
        if (val_index_.end() == it) {
            return false;
        }
        int index = it->second;
        int last_index = vals_.size() - 1;
        int last_val = vals_[last_index];
        vals_[index] = last_val;
        vals_.pop_back();
        val_index_[last_val] = index; 
        val_index_.erase(val);
        return true;
    }
    int get_random() {
        std::random_device rd;  
        std::mt19937 gen(rd());  
        std::uniform_int_distribution<> dis(0, vals_.size() - 1);  
        int index = dis(gen);
        return vals_[index];
    }
    inline int get_size() const {
        return vals_.size();
    }
};