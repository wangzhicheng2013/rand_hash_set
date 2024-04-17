#include <stdio.h>
#include "random_hash_set.hpp"
#include "random_hash_setmap.hpp"
#include "time_elapse.hpp"
// ./Test  100000
// elapse = 131.838910s
// size = 47752
// =======================================
// elapse = 4.557741s
// size = 47733
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("input loop!\n");
        return -1;
    }
    int loop = atoi(argv[1]);
    if (loop <=0 || loop > 10000000) {
        printf("loop should be between 0 and 10000000\n");
        return -1;
    }
    std::random_device rd;
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dis(-loop, loop);
    std::vector<int>random_nums;
    for (int i = -loop;i <= loop;i++) {
        random_nums.push_back(dis(gen));
    }
    random_hash_set rhs;
    time_elapse te;
    te.start();
    for (int i = 0;i < random_nums.size();i++) {
        rhs.insert(random_nums[i]);
        rhs.get_random();
        if (i > random_nums.size() / 2) {
            rhs.remove(rhs.get_random());
        }
    }
    printf("elapse = %lfs\n", te.end());
    printf("size = %d\n", rhs.get_size());
    printf("=======================================\n");
    random_hash_setmap rhsm;
    te.start();
    for (int i = 0;i < random_nums.size();i++) {
        rhsm.insert(random_nums[i]);
        rhsm.get_random();
        if (i > random_nums.size() / 2) {
            rhsm.remove(rhsm.get_random());
        }
    }
    printf("elapse = %lfs\n", te.end());
    printf("size = %d\n", rhsm.get_size());

    return 0;
}