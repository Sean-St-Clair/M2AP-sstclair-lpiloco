// Created by sstclair and lpiloco 2/22/2023

#ifndef M2AP_SHUFFLEVECTOR_H
#define M2AP_SHUFFLEVECTOR_H

#include <vector>
#include <optional>
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
class ShuffleVector {
private:
    vector<T> vec;

    vector<T> sortVecRec(vector<T> vec) {
        if (vec.size() <= 1) {
            return vec;
        }

        // Choose a partition element
        T partition = vec[0];

        vector<T> smaller, equal, larger;
        // Loop through vec and populate smaller, equal, larger
        int i;
        for (i = 0; i < vec.size(); ++i) {
            if (vec[i] < partition) {
                smaller.push_back(vec[i]);
            } else if (vec[i] > partition) {
                larger.push_back(vec[i]);
            } else {
                equal.push_back(vec[i]);
            }
        }

        // Recursive calls
        sortVecRec(smaller);
        sortVecRec(larger);

        // Copy elements from smaller, equal, and larger back into vec
        for (i = 0; i < vec.size(); ++i) {
            if (i < smaller.size()) {
                vec[i] = smaller[i];
            } else if (i < smaller.size() + equal.size()) {
                vec[i] = equal[i - smaller.size()];
            } else {
                vec[i] = larger[i - smaller.size() - equal.size()];
            }
        }
        return vec;
    }

public:
    ShuffleVector() {
        vec = {};
    }

    ShuffleVector(vector<T> vec) {
        this->vec = vec;
    }

    // Getters
    vector<T> getVector() {
        return vec;
    }

    // Setters
    void setVector(vector<T> vec) {
        this->vec = vec;
    }

    void randomizeSstclair() {
        
    }

    void randomizeLpiloco() {

    }

    void sortVector() {
        sortVecRec(vec);
    }

    optional<T> findItem(T item) {
        return nullopt;
    }

    optional<T> findItemByIndex(int index) {
        return nullopt;
    }

    friend ostream &operator<<(ostream &outs, const ShuffleVector &vec) {
        outs << "Test hi" << endl;
        return outs;
    }

};

#endif //M2AP_SHUFFLEVECTOR_H
