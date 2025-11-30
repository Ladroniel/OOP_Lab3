#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include "square.hpp"
#include "rectangle.hpp"
#include "trapecia.hpp"

static void print_menu() {
    std::cout << "Меню:\n";
    std::cout << "1) Добавить фигуру (квадрат/прямоугольник/трапеция)\n";
    std::cout << "2) Показать все фигуры\n";
    std::cout << "3) Показать центры и площади\n";
    std::cout << "4) Суммарная площадь\n";
    std::cout << "5) Удалить по индексу (0..n-1)\n";
    std::cout << "0) Выход\n";
    std::cout << "> ";
}

int main() {
    std::vector<std::unique_ptr<Figure>> figs;
    for (;;) {
        print_menu();
        int cmd;
        if (!(std::cin >> cmd)) return 0;
        if (cmd == 0) break;

        if (cmd == 1) {
            std::cout << "Тип (1=квадрат, 2=прямоугольник, 3=трапеция): ";
            int t; std::cin >> t;
            try {
                if (t == 1) {
                    std::cout << "Введите две точки (x y x y) для построения квадрата: ";
                    auto f = std::make_unique<Square>();
                    std::cin >> *f;
                    figs.push_back(std::move(f));
                } else if (t == 2) {
                    std::cout << "Введите 4 вершины прямоугольника по порядку: ";
                    auto f = std::make_unique<Rectangle>();
                    std::cin >> *f;
                    figs.push_back(std::move(f));
                } else if (t == 3) {
                    std::cout << "Введите 4 вершины трапеции по порядку: ";
                    auto f = std::make_unique<Trapezoid>();
                    std::cin >> *f;
                    figs.push_back(std::move(f));
                } else {
                    std::cout << "Неизвестный тип\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
                std::cin.clear();
            }
        } else if (cmd == 2) {
            for (size_t i=0;i<figs.size();++i) {
                std::cout << i << ": " << *figs[i] << "\n";
            }
        } else if (cmd == 3) {
            for (size_t i=0;i<figs.size();++i) {
                auto c = figs[i]->center();
                double s = figs[i]->area();
                std::cout << i << ": центр=("<<c.x<<","<<c.y<<") площадь="<< s << "\n";
            }
        } else if (cmd == 4) {
            double sum = 0.0;
            for (auto& f : figs) sum += f->area();
            std::cout << "Суммарная площадь: " << sum << "\n";
        } else if (cmd == 5) {
            std::cout << "Индекс: ";
            size_t idx; std::cin >> idx;
            if (idx < figs.size()) {
                figs.erase(figs.begin() + idx);
                std::cout << "Удалено\n";
            } else {
                std::cout << "Неверный индекс\n";
            }
        } else {
            std::cout << "Команда не распознана\n";
        }

        if (std::cin.peek()=='\n') std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return 0;
}
