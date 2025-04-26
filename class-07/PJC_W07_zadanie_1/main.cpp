#include <iostream>
#include <fmt/ranges.h>
#include <fmt/format.h>

template <typename T>
struct Matrix {
    std::vector<std::vector<T>> matrix;

    Matrix(std::vector<std::vector<T>> m): matrix(m) { }

    Matrix(int r, int c, T e) {
        matrix = std::vector<std::vector<T>>(r);

        for(auto& row: matrix) {
            row = std::vector<T>(c);

            for(auto& col: row) {
                col = e;
            }
        }
    }

    auto getRowSize() const -> int {
        return matrix.size();
    }

    auto getColSize() const -> int {
        if(matrix.size() == 0) {
            return 0;
        }
        return matrix[0].size();
    }

    auto operator=(Matrix other) -> Matrix& {
        matrix = other.matrix;
        return *this;
    }

    auto operator+(Matrix other) -> Matrix {
        auto res = Matrix(matrix);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return res;
    }

    auto operator-(Matrix other) -> Matrix {
        auto res = Matrix(matrix);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                res.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return res;
    }

    auto operator*(Matrix other) -> Matrix {
        auto res = Matrix(getRowSize(), other.getColSize(), matrix[0][0]);

        // if(getColSize() == other.getRowSize()) { }

        for(int i = 0; i < res.matrix.size(); i++) {
            for(int j = 0; j < res.matrix.size(); j++) {
                auto counter = 0;
                auto sum = 0;

                auto k = i;
                auto n = j;
                auto l = 0;
                auto m = 0;

                auto e1 = 0;
                auto e2 = 0;

                while(counter < getColSize()) {
                    e1 = matrix[k][l];
                    e2 = other.matrix[m][n];

                    ++l;
                    ++m;

                    ++counter;
                    sum += (e1 * e2);
                }

                res.matrix[i][j] = sum;
            }
        }

        return res;
    }

    auto transpose() -> void {
        auto res = std::vector<std::vector<T>>(getColSize());
        for(auto i = 0; i < matrix[0].size(); i++) {
            for(auto j = 0; j < matrix.size(); j++) {
                res[i].push_back(matrix[j][i]);
            }
        }
        matrix = res;
    }
};

template <typename T>
auto format_as(Matrix<T> m) -> std::string {
    auto result = std::string();

    for(auto const& row: m.matrix) {
        for(auto const& col: row) {
            result += fmt::to_string(col) + " ";
        }
        result += "\n";
    }
    result.erase(result.end() - 1);
    return result;
}

auto main() -> int {
    auto m1 = Matrix<int>(2, 3, 1);
    fmt::println("{}\n", m1);
    // fmt::println("{}\n", m1.getRowSize());
    // fmt::println("{}\n", m1.getColSize());
    auto m2 = Matrix<int>(3, 2, 1);
    fmt::println("{}\n", m2);
    auto m3 = m1 * m2;
    fmt::println("{}", m3);

    // auto m1 = Matrix<int>({{1, 2, 3, 4, 5,}});
    // auto m2 = Matrix<int>({{1}, {2}, {3}, {4}, {5}});
    // fmt::println("{}\n\n{}\n", m1, m2);
    //
    // auto m3 = m1 * m2;
    // auto m4 = m2 * m1;
    // fmt::println("{}\n\n{}\n", m3, m4);
}