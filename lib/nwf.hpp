#include "json/json.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <filesystem> 
#include <string>
#include <iostream>

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>

#endif

void new_dir(const std::string& dirname) {
    #ifdef __linux__
        std::filesystem::create_directory(dirname);
    #elif _WIN32 
        CreateDirectoryA(dirname.c_str(),NULL);
    #endif
    
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
