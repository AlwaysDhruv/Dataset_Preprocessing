#ifndef PREPROCESśS_H
#define PREPROCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Preprocess
{
public:
    void create_pixels_txt(vector<string>& folder_name)
    {
        string path;
        cout << "Path :- " ;
        cin >> path;
        if (path!="")
        {
            for (const auto& entry : fs::directory_iterator(path))
            {
                if (entry.is_directory())
                {
                    folder_name.push_back(entry.path().filename().string());
                }
            }
            for (int i = 0; i < folder_name.size(); ++i)
            {
                string folder_path  = path + folder_name[i];
                string command = "python preprocess.py \"" + folder_path + "\"";
                int result = system(command.c_str());
                if (result != 0) 
                {
                    cout << "Python preprocessing failed.\n";
                }
            }
            cout << "File Created..." << endl;
            cout << endl << endl;
        }
        else cout << "Invalid path" << endl;
    }
};
#endif