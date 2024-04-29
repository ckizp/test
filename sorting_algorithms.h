#ifndef VISUALSORT_SORTING_ALGORITHMS_H_
#define VISUALSORT_SORTING_ALGORITHMS_H_

#include <iostream>
#include <vector>
#include "sequence_factory.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Grid.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "sorting_algorithm_datas.h"

namespace SortingAlgorithm {
    enum Type {
        kInsertion,
        kQuick,
        kQuick3,
        kMerge,
        kSelection,
        kBubble,
        kShell,
        kHeap,
    };

    static const Type All[] = { kInsertion, kQuick, kQuick3, kMerge, kSelection, kBubble, kShell, kHeap };

    std::string toString(Type);
}

class SortingAlgorithms {
public:
    std::vector<int> sort(std::vector<int>, SAlgoDatas&);

    SortingAlgorithms(ProblemSize::Type, SortingAlgorithm::Type);
    void Launch();
    void createView(tgui::Gui &gui);
    void createDatasGrid(tgui::Grid::Ptr grid);
private:
    SortingAlgorithm::Type current_algorithm;
    //std::unordered_map<InitialOrder::Type, AResultsLayout*> results_layout;
    std::unordered_map<InitialOrder::Type, std::vector<int>> sequences;
    ProblemSize::Type size;
    SortingAlgorithm::Type algorithm;

    void reloadSequences();

    // Tri par insertion
    std::vector<int> InsertionSort(std::vector<int>, SAlgoDatas&);

    // Tri rapide
    std::vector<int> QuickSort(std::vector<int>&, int, int);
    int Partition(std::vector<int>&, int, int);

    // Tri fusion
    std::vector<int> MergeSort(std::vector<int>);
    std::vector<int> Merge(std::vector<int>&, std::vector<int>&);

    void onButtonPressRenderer(tgui::Button::Ptr b);
    void resetButtonRenderer(tgui::Button::Ptr);
};

#endif // VISUALSORT_SORTING_ALGORITHMS_H_