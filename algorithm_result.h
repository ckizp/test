#ifndef VISUALSORT_ALGORITHM_RESULT_H_
#define VISUALSORT_ALGORITHM_RESULT_H_

#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "sorting_algorithm_datas.h"

class AResultsLayout {
public:
    AResultsLayout(InitialOrder::Type);
    tgui::VerticalLayout::Ptr getLayout() const;
    void setExecutionTimeText(std::string);
    void setSwapCountText(std::string);
    void setComparisonCountText(std::string);
    void clear();
    void show(SAlgoDatas);

private:
    tgui::VerticalLayout::Ptr layout;
    tgui::Label::Ptr execution_time_label;
    tgui::Label::Ptr swap_count_label;
    tgui::Label::Ptr comparison_count_label;
};

#endif // VISUALSORT_ALGORITHM_RESULT_H_
