// Created by sstclair and lpiloco 2/22/2023

#ifndef M2AP_SHUFFLEVECTOR_H
#define M2AP_SHUFFLEVECTOR_H

#include <vector>
#include <optional>
#include <iostream>
#include <iomanip>
#include <ctime>

#include <algorithm>
#include <random>

using namespace std;

template<typename T>
class ShuffleVector {
private:
    vector<T> vec;

    vector<T> sortVecRec(vector<T> &vec) {
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
    vector<T> getVector() const {
        return vec;
    }

    // Setters
    void setVector(vector<T> vec) {
        this->vec = vec;
    }

    void randomizeSstclair() {
        /*auto rng = std::default_random_engine{};
        std::shuffle(std::begin(vec), std::end(vec), rng);*/

        int index1;
        int index2;
        T temp;
        for (int i = 0; i < size(vec); ++i) {
            index1 = (time(0) * i) % size(vec);
            index2 = time(0) % size(vec);
            temp = vec[index1];
            vec[index1] = vec[index2];
            vec[index2] = temp;
        }
        for (int i = 0; i < size(vec); ++i) {
            cout << vec[i] << endl;
        }
    }

    void randomizeLpiloco() {
        int index;
        T temp;
        for (int i = 0; i < size(vec); ++i) {
            index = (time(0) * i) % size(vec);
            temp = vec[i];
            vec[i] = vec[index];
            vec[index] = temp;
//            for (int j = 0; j < size(vec); ++j) {
//                cout << vec[j] << " ";
//            }
//            cout << endl;
        }
    }

    void sortVector() {
        vec = sortVecRec(vec);
    }

    void addItem(T item) {
        vec.push_back(item);
    }

    optional<T> findItem(T item) {
        for (int i = 0; i < vec.size(); ++i)
            if (item == vec[i])
                return vec[i];
        return nullopt;
    }

    friend ostream &operator<<(ostream &outs, const ShuffleVector &v) {
        for (int i = 0; i < size(v.getVector()); ++i) {
            outs << v.getVector()[i] << " ";
        }
        return outs;
    }

};

#endif //M2AP_SHUFFLEVECTOR_H
