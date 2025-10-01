// #include <chrono>
// #include <consoleUtils.hh>
// #include <fstream>
// #include <functional>
// #include <iostream>
// #include <l5/include/screens.hh>
// #include <l5/include/vector.hh>
// #include <l7/include/flight.hh>
// #include <memory>
// using namespace std;
// using namespace console_utils;
// using namespace screens;

// int main(void) {
//     static array<function<bool()>, 5> actions = {
//         [&vec1]() { return inputVector(vec1); },
//         [&vec2]() { return inputVector(vec2); },
//         [&vec1, &vec2]() { return printVectors(vec1, vec2); },
//         [&vec1, &vec2]() { return addVectors(vec1, vec2); },
//         []() { return false; },

//     // };
//     // unsigned int response;
//     // do {
//     //     printMainScreen();
//     //     readT(response, ">", [](unsigned int num) { return num > 0 && num <= 5; });
//     //     cout << "\x{1B}[2J\x{1B}[H\n";
//     // } while (actions[response - 1]());
//     str::String str1;
//     int num;
//     time_t t = time(nullptr);
//     Flight fl{"Hawai", t, t};
//     Flight fl2{"Hrodno", t, time(nullptr)};
//     Flight fl3{"Ulupinsk", time(nullptr) + 1, time(nullptr)};

//     auto vecc = Flight::getByDepartureTime(t);
//     std::ifstream in("test.bin", ios::binary);
//     std::ofstream out("test.bin", ios::binary);
//     out << fl2;
//     in >> fl2;
//     cout << fl2.dump();

//     return 0;
// }
