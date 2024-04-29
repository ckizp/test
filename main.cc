#include "sorting_algorithms.h"

int main() {
    // On définit par défaut des séquences de taille petite et l'algorithme par insertion.
    SortingAlgorithms sa(ProblemSize::kSmall, SortingAlgorithm::kInsertion);
    sa.Launch();
    return 0;
}
