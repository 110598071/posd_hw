#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stdexcept>

class Scanner {
    public:
        Scanner(std::string input):  _input(input) {
            for (std::string token : tokenList) {
                std::size_t pos = 0;
                while (_input.find(token, pos) != std::string::npos) {
                    // std::size_t found = _input.find(token);
                    auto tokenTuple = std::make_tuple(token, _input.find(token, pos));
                    recordTokenVector.push_back(tokenTuple);
                    // recordTokenVector_backup.push_back(tokenTuple);
                    pos = _input.find(token, pos) + token.size();
                }
            }

            int nexDouble = -1;
            for (int i=0; i<_input.size(); i++) {
                if (isdigit(_input.at(i)) && i > nexDouble) {
                    int doubleLength = 1;
                    while ((i+doubleLength) != _input.size() && (isdigit(_input.at(i+doubleLength)) || _input.at(i+doubleLength) == '.')) {
                        doubleLength += 1;
                    }
                    doubleQueue.push(_input.substr(i, doubleLength));
                    // doubleQueue_backup.push(_input.substr(i, doubleLength));
                    nexDouble = i + doubleLength -1;
                }
            }
        }

        std::string next() {
            if (recordTokenVector.empty()) {
                throw std::out_of_range("out of range");
            }
            else {
                auto firstTuple = recordTokenVector.front();
                std::size_t minPos = std::get<1>(firstTuple);
                int vectorPos = 0;
                int recordPos = 0;

                for (auto tokenTuple : recordTokenVector) {
                    if (std::get<1>(tokenTuple) < minPos) {
                        minPos = std::get<1>(tokenTuple);
                        firstTuple = tokenTuple;
                        recordPos = vectorPos;
                    }
                    vectorPos += 1;
                }
                recordTokenVector.erase(recordTokenVector.begin() + recordPos);

                return std::get<0>(firstTuple);
            }
        }

        double nextDouble() {
            if (doubleQueue.empty()) {
                throw std::out_of_range("out of range");
            }
            else {
                std::string recordDouble = doubleQueue.front();
                doubleQueue.pop();
                return stof(recordDouble);
            }
        }

        bool isDone() {
            return recordTokenVector.empty() && doubleQueue.empty();
        }

        // void printTest() {
        //     while (!recordTokenVector_backup.empty()) {
        //         auto firstTuple = recordTokenVector_backup.front();
        //         std::size_t minPos = std::get<1>(firstTuple);
        //         int vectorPos = 0;
        //         int recordPos = 0;

        //         for (auto tokenTuple : recordTokenVector_backup) {
        //             if (std::get<1>(tokenTuple) < minPos) {
        //                 minPos = std::get<1>(tokenTuple);
        //                 firstTuple = tokenTuple;
        //                 recordPos = vectorPos;
        //             }
        //             vectorPos += 1;
        //         }
        //         recordTokenVector_backup.erase(recordTokenVector_backup.begin() + recordPos);

        //         std::cout << "Token: " << std::get<0>(firstTuple) << " POS: " << std::get<1>(firstTuple) << std::endl;
        //     }

        //     while (!doubleQueue_backup.empty()) {
        //         std::string recordDouble = doubleQueue_backup.front();
        //         doubleQueue_backup.pop();
        //         std::cout << "Double: " << stof(recordDouble) << std::endl;
        //     }
        // }

    private:
        std::vector<std::tuple<std::string, std::size_t>> recordTokenVector;
        std::queue<std::string> doubleQueue;
        // std::vector<std::tuple<std::string, std::size_t>> recordTokenVector_backup;
        // std::queue<std::string> doubleQueue_backup;
        const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape", "(", ")", "[", "]", "{", "}", ","};
        std::string _input;
        int pos = 0;
};