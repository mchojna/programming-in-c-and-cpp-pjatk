#include <iostream>
#include <fmt/ranges.h>
#include <fmt/format.h>

class Student {
public:
    Student(std::string n, std::string s, int id, int sem) {
        name = n;
        surname = s;
        index = id;
        semester = sem;
    }

    auto getName() const -> std::string { return name; }
    auto setName(std::string i ) -> void { name = i; }

    auto getSurname() const -> std::string { return surname; }
    auto setSurname(std::string n ) -> void { surname = n; }

    auto getIndex() const -> int { return index; }
    auto setIndex(int nst ) -> void { index = nst; }

    auto getSemester() const -> int { return semester; }
    auto setSemester(int nsm ) -> void { semester = nsm; }

private:
    std::string name;
    std::string surname;
    int index;
    int semester;
};

auto format_as(Student const& s) {
    return fmt::format("{} {} {} {}", s.getName(), s.getSurname(), s.getIndex(), s.getSemester());
}

enum class StudentsSort {
    Name, Surname, Index, Semester
};

auto sameSemester(std::vector<Student> const& students) -> bool {
    auto semester = students[0].getSemester();
    for(Student const& student: students) {
        if(student.getSemester() != semester) {
            return false;
        }
    }
    return true;
}

auto sort(std::vector<Student>& students, StudentsSort studentsSort) -> void {
    std::ranges::sort(students, [studentsSort](Student const& s1, Student const& s2) -> bool {
        switch(studentsSort) {
            case StudentsSort::Name: {
                return s1.getName() < s2.getName();
            }
            case StudentsSort::Surname: {
                return s1.getSurname() < s2.getSurname();
            }
            case StudentsSort::Index: {
                return s1.getIndex() < s2.getIndex();
            }
            case StudentsSort::Semester: {
                return s1.getSemester() < s2.getSemester();
            }
        }
    });
}

auto main() -> int {
    auto students = std::vector<Student>{
        Student("Tomasz", "Kowalski", 1, 6),
        Student("Maciej", "Wisniewski", 4, 1),
        Student("Adam", "Mlodawski", 9, 4),
        Student("Krzysztof", "Adamowicz", 28, 3),
        Student("Barbara", "Gregorczyk", 35, 4),
    };

    fmt::println("{}", sameSemester(students));

    sort(students, StudentsSort::Name);
    fmt::println("{}", students);

    sort(students, StudentsSort::Surname);
    fmt::println("{}", students);

    sort(students, StudentsSort::Index);
    fmt::println("{}", students);

    sort(students, StudentsSort::Semester);
    fmt::println("{}", students);
}
