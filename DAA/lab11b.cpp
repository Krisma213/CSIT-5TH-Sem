#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[] = {{'A',2,100}, {'B',1,19}, {'C',2,27}, {'D',1,25}, {'E',3,15}};
    int n = 5;

    sort(jobs, jobs + n, cmp);

    int result[5] = {0};
    bool slot[5] = {false};

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for(int i = 0; i < n; i++) {
        if(slot[i])
            cout << jobs[result[i]].id << " ";
    }
}