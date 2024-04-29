#include "algorithm_result.h"
#include "TGUI/Widgets/HorizontalLayout.hpp"
#include <fstream>

AResultsLayout::AResultsLayout(InitialOrder::Type initial_order) {
    layout = tgui::VerticalLayout::create();

    tgui::Label::Ptr initial_order_label = tgui::Label::create(InitialOrder::toString(initial_order));
    initial_order_label->getRenderer()->setTextStyle(sf::Text::Bold);
    initial_order_label->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
    initial_order_label->setVerticalAlignment(tgui::Label::VerticalAlignment::Center);

    tgui::HorizontalLayout::Ptr time_layout = tgui::HorizontalLayout::create();
    tgui::Label::Ptr execution_time_prefix_label = tgui::Label::create("Execution time: ");
    execution_time_label = tgui::Label::create("-");
    time_layout->add(execution_time_prefix_label);
    time_layout->add(execution_time_label);

    tgui::HorizontalLayout::Ptr swap_layout = tgui::HorizontalLayout::create();
    tgui::Label::Ptr swap_count_prefix_label = tgui::Label::create("Swap count: ");
    swap_count_label = tgui::Label::create("-");
    swap_layout->add(swap_count_prefix_label);
    swap_layout->add(swap_count_label);

    tgui::HorizontalLayout::Ptr comparison_layout = tgui::HorizontalLayout::create();
    tgui::Label::Ptr comparison_count_prefix_label = tgui::Label::create("Comparison count: ");
    comparison_count_label = tgui::Label::create("-");
    comparison_layout->add(comparison_count_prefix_label);
    comparison_layout->add(comparison_count_label);

    layout->add(initial_order_label);
    layout->add(time_layout);
    layout->add(swap_layout);
    layout->add(comparison_layout);
}

tgui::VerticalLayout::Ptr AResultsLayout::getLayout() const {
    return layout;
}

void AResultsLayout::setExecutionTimeText(std::string s) {
    execution_time_label->setText(s);
}

void AResultsLayout::setSwapCountText(std::string s) {
    swap_count_label->setText(s);
}

void AResultsLayout::setComparisonCountText(std::string s) {
    comparison_count_label->setText(s);
}

void AResultsLayout::clear() {
    execution_time_label->setText("-");
    swap_count_label->setText("-");
    comparison_count_label->setText("-");
}

void AResultsLayout::show(SAlgoDatas datas) {
    setExecutionTimeText(std::to_string(datas.execution_time) + "s");
    setSwapCountText(std::to_string(datas.swap_count));
    setComparisonCountText(std::to_string(datas.comparison_count));
}