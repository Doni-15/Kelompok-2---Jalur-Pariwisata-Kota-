#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "dataSet.hpp"

class MergeSort{
    private:

    public:
        MergeSort();
        bool compare(const string& a, const string& b, const string& mode);
        void conquere(vector<string>& arr, int left, int mid, int right, const string& mode);
        void devine(vector<string>& arr, int left, int right, const string& mode);
        void printList(const string& judul, const vector<string>& namaDaftar);
};

#endif