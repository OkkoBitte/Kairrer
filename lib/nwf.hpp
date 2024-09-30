#include <iostream>
#include "json/json.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string> 

void new_dir(const std::string& dirname) {
    // win32
    CreateDirectoryA(dirname.c_str(), NULL);
}


template <typename T>
void new_file(const std::string& filename, const T& write_data) {
    std::ofstream ofa(filename);
    ofa << write_data;
    ofa.close();
}

// Json::Value read_json(const std::string& filename) {
//     std::ifstream file(filename);
//     Json::Reader reader;
//     Json::Value data;
//     return data;
// }

// void write_json(const std::string& filename, const Json::Value& data) {
//     std::ofstream file(filename);
//     Json::StyledStreamWriter writer;
//     writer.write(file, data);
// }
