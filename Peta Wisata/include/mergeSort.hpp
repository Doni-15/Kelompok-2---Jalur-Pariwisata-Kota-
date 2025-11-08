#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "dataSet.hpp"

class MergeSort{
    private:
        static bool compare(const string& a, const string& b, const string& mode);
        static void conquere(vector<string>& arr, int left, int mid, int right, const string& mode);
        static void devine(vector<string>& arr, int left, int right, const string& mode);
        static void printList(const string& judul, const vector<string>& namaDaftar);

    public:
        MergeSort();
};

#endif