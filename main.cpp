#include "lib/nwf.hpp"//              WELCOM TO PROJECT Rairrer
#include "lib/cpython.h"
#include "lib/webm.hpp"

class root {
    public:class path{
        // python --.
        public:std::string lib_pyhon_nwf = "import os\nimport shutil\nimport json\ndef new_file(name,w):\n\twith open(name,\"w\") as f:\n\t\tf.write(w)\ndef new_dir(name):\n\tos.mkdir(name)\ndef at_file(name,w):\n\twith open(name,\"a+\") as f:\n\t\tf.write(w)\ndef read_file(name):\n\twith open(name,\"r\") as f:\n\t\tret = f.read()\n\t\treturn ret\ndef del_file_all(name):\n\tshutil.rmtree(name)\ndef del_file(name):\n\tos.remove(name)\ndef is_file(name):\n\treturn os.path.isfile(name)\ndef is_dir(name):\n\treturn os.path.isdir(name)\ndef js_input(name,w):\n\twith open(name,\"w\")as f:\n\t\tjson.dump(w,f, indent=4)\ndef js_output(name):\n\twith open(name,\"r\")as f:\n\t\treturn json.load(f)";
        // ^ LIB ^
        public:std::string main_python_file_content="import lib.nwf as file\n\n\"\"\"\nWelcom MBG Kairrer!\n\"\"\"\n\ndef main(arg=None):\n\tprint(\"Hello Kairrer!\")\n\nif __name__==\"__main__\":\n\tmain()";
        // java --. 
        public:std::string main_java_file_content="\n// Kairrer - java\n\npublic class Main{\n\tpublic static void main(String[] argc){\n\t\tSystem.out.println(\"Hello Kairrer!\");\t\n}\n}";
        // kairrer sys txts --.
        public:std::string start_help_str="Kairrer dev manager.\nkairrer <command || arguments>\n[command]\n\tinit | init project; -python, -java, -c/cpp ...\n\trun  | run project; -python ....\n\n[-arguments]\n\t-python  -> init -python | init project\n\t-java    -> init -java   | init project\n[!MBG]";
    };
};
//  

int main(int argc, char* arvs[]) {
    root  root;
    root::path path;
    print(webm::get("https://web-mbg.ru"));
    if (argc < 2) {
        print(path.start_help_str);
    }
    else{
        for (int i = 1; i < argc; ++i) {
            std::string arg = arvs[i];

            if (arg == "init"  ||  arg=="-python" || arg=="-java") {
                if (arg == "-python"){
                    int is_python=system("python");
                    if (is_python==1){

                    }
                    new_dir("lib");
                    new_file("lib/nwf.py",path.lib_pyhon_nwf);
                    new_file("main.py",path.main_python_file_content);

                }
                else if(arg == "-java"){
                    new_dir("java");
                    new_dir("java/lib");
                    new_dir("java/res");
                    new_dir("java/src");
                    new_file("java/src/Main.java",path.main_java_file_content);
                }
                else{
                    print("kairrer init Kairrer Projcet");
                }
            }
            
            else if (arg == "run") {

            }
            else if (arg == "-version") {
                std::cout << "Version: alpha .1.4" << std::endl;
            } else {
                print(path.start_help_str);
            }
        }
    }
  
    return 0;
}

