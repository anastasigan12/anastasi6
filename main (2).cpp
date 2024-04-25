#include <iostream>
#include <string>

size_t custom_find_first_of(const std::string& str, const std::string& chars, size_t pos = 0) {
    for (size_t i = pos; i < str.length(); ++i) {
        if (chars.find(str[i]) != std::string::npos) {
            return i;
        }
    }
    return std::string::npos;
}

std::string transformString(const std::string& S, int N) {
    if (N <= 0) {
        std::cerr << "Invalid input: N should be greater than 0." << std::endl;
        return "";
    }

    int S_length = S.length();

    if (S_length == N) {
        return S;
    } else if (S_length > N) {
        return S.substr(S_length - N);
    } else {
        std::string result(N - S_length, '.');
        result += S;
        return result;
    }
}

int main() {
    std::string str = "Hello, world!";
    std::string chars = ".,;:!";

    size_t found = custom_find_first_of(str, chars);
    if (found != std::string::npos) {
        std::cout << "Found character '" << str[found] << "' at position " << found << std::endl;
    } else {
        std::cout << "No characters from the provided set found in the string." << std::endl;
    }

    int N;
    std::string S;

    // Ввод данных
    std::cout << "Введите целое число N (> 0): ";
    std::cin >> N;

    std::cout << "Введите строку S: ";
    std::cin >> S;

    // Преобразование строки
    std::string transformedString = transformString(S, N);

    // Вывод результата
    std::cout << "Преобразованный строка: " << transformedString << std::endl;

    return 0;
}