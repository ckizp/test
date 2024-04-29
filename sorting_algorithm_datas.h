#ifndef VISUALSORT_SORTING_ALGORITHM_DATAS_H_
#define VISUALSORT_SORTING_ALGORITHM_DATAS_H_

#include "sorting_algorithms.h"

struct SAlgoDatas {
    SortingAlgorithm::Type sorting_algorithm;
    InitialOrder::Type initial_order;
    ProblemSize::Type problem_size;
    double execution_time;
    int swap_count;
    int comparison_count;

    void log() const;
};

#endif // VISUALSORT_SORTING_ALGORITHM_DATAS_H_
