//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <set>
//#include <algorithm>
//#include <locale>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "");
//
//    cout << "Задача 1:\nВведите строку чисел: ";
//    string line;
//    getline(cin, line);
//    stringstream ss(line);
//    int sum_task1 = 0;
//    int num;
//    while (ss >> num) {
//        sum_task1 += num;
//    }
//    cout << "Сумма чисел: " << sum_task1 << "\n\n";
//
//    cout << "Задача 2:\nВведите список чисел: ";
//    getline(cin, line);
//    stringstream ss2(line);
//    vector<int> arr;
//    while (ss2 >> num) {
//        arr.push_back(num);
//    }
//    int n = arr.size();
//
//    if (n == 0) {
//        cout << "\n";
//    }
//    else if (n == 1) {
//        cout << arr[0] << "\n";
//    }
//    else {
//        vector<int> result;
//        for (int i = 0; i < n; ++i) {
//            int left = arr[(i - 1 + n) % n];
//            int right = arr[(i + 1) % n];
//            result.push_back(left + right);
//        }
//       
//        for (size_t i = 0; i < result.size(); ++i) {
//            cout << result[i] << (i == result.size() - 1 ? '\n' : ' ');
//        }
//    }
//    cout << "\n";
//
//    cout << "Задача 3:\nВведите список чисел: ";
//    getline(cin, line);
//    stringstream ss3(line);
//    vector<int> numbers;
//    while (ss3 >> num) {
//        numbers.push_back(num);
//    }
//
//    sort(numbers.begin(), numbers.end());
//    set<int> duplicates;
//    for (size_t i = 1; i < numbers.size(); ++i) {
//        if (numbers[i] == numbers[i - 1]) {
//            duplicates.insert(numbers[i]);
//        }
//    }
//
//    for (auto it = duplicates.begin(); it != duplicates.end(); ++it) {
//        cout << *it << (next(it) == duplicates.end() ? '\n' : ' ');
//    }
//
//    return 0;
//}


#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>

using namespace std;

double calculate_gc_content(const string& str) {
    int count_GC = 0;
    int total = str.size();
    for (char ch : str) {
        char lowerCh = tolower(ch);
        if (lowerCh == 'g' || lowerCh == 'c') {
            count_GC++;
        }
    }
    if (total == 0) return 0.0; 
    return (static_cast<double>(count_GC) / total) * 100;
}

string encode_string(const string& str) {
    if (str.empty()) return "";
    string result;
    char current_char = str[0];
    int count = 1;
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] == current_char) {
            count++;
        }
        else {
            result += current_char + to_string(count);
            current_char = str[i];
            count = 1;
        }
    }
    result += current_char + to_string(count);
    return result;
}

int main() {
    setlocale(LC_ALL, "");

    cout << "Введите строку для расчета GC-содержания:\n";
    string dnaStr;
    getline(cin, dnaStr);
    double gcPercent = calculate_gc_content(dnaStr);
    cout << fixed << setprecision(1);
    cout << "Процентное содержание G и C: " << gcPercent << "%\n";

    cout << "Введите строку для кодирования:\n";
    string encodeStr;
    getline(cin, encodeStr);
    string encoded = encode_string(encodeStr);
    cout << encoded << endl;

    return 0;
}