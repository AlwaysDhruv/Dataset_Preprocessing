#ifndef PREPROCESśS_H
#define PREPROCESS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Pixels
{
public:
    void read_pixels()
    {
        ifstream file("pixels.txt");
        if (file.is_open())
        {
            int count;
            int ct = 0;
            string line;
            string token;
            int imge = 0;
            vector<double> pixel;
            vector<vector<double>> pixels;
            cout << "How Many :- ";
            cin >> count;
            while (getline(file, line))
            {
                stringstream ss(line);
                while (getline(ss, token, ','))
                {
                        pixel.push_back(stod(token));
                        ++ct;
                    if (ct==28)
                    {
                        pixels.push_back(pixel);
                        pixel.clear();
                        ct = 0;
                    }
                }
                cout << "===============================" << endl;
                cout << imge + 1 << ". Image Shape :- " << pixels.size() << " " << pixels[0].size() << endl;
                cout << "===============================" << endl;
                show(pixels);
                cout << "===============================" << endl;
                cout << endl << endl;
                ++imge;
                ct = 0;
                pixel.clear();
                pixels.clear();
                if (imge==count) break;
            }
            cout << "Count Of Images :- " << imge << endl;
            cout << endl << endl;
            imge = 0;
        }
        else
        {
            cout << "File Not Found..." << endl;
        }
    }
    void show(vector<vector<double>>& v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v[0].size(); ++j)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};
#endif