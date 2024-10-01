#include <iostream>
#include <string>
#ifdef __linux__
    #include <curl/curl.h>
#elif __WIN32
    #include <windows.h>
    #include <wininet.h>
#endif

namespace webm {
    size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
        std::string *output = reinterpret_cast<std::string*>(stream);
        *output += std::string(static_cast<char*>(ptr), size * nmemb);
        return size * nmemb;
    }
    std::string get(std::string url) {
        #ifdef __linux__
            CURL *curl;
            CURLcode res;
            std::string response;

            curl = curl_easy_init();
            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);

                if (res != CURLE_OK) {
                    std::cerr << "ERR = > " << curl_easy_strerror(res) << std::endl;
                }

                return response;
            } else {
                std::cerr << "ERR cURL;" << std::endl;
                return "";
            }
        #elif _WIN32
            const char * urlc=url.c_str();
            std::string fullCMD="curl " + *urlc + *"&& pass";
            int result=std::system(fullCMD.c_str());
            
        #endif
    }
}

