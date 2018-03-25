#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map <string, char> reverseMap (unordered_map<char, string> source){
    unordered_map <string, char> reversed_map;
    for (auto it:  source){
        reversed_map[it.second] = it.first;
    }
    return reversed_map;
}

int main()
{
    ifstream source("KP_0005.txt");
    ifstream code("Kody.csv");
    ofstream coded_file("coded.txt");
    ofstream un_coded_file("un_coded.txt");

    unordered_map<char, string> mapa_kod;
    unordered_map<string, char> mapa_kod_odwrocony;

    string linia;
    while (getline(code, linia))
    {
        mapa_kod[linia[0]] = linia.substr(3, 5);
    }
    code.close();

    char znak;
    while(source.get(znak))
    {
        coded_file << mapa_kod[znak];
    }

    mapa_kod_odwrocony = reverseMap(mapa_kod);
    coded_file.close();

    ifstream coded_file_to_read("coded.txt");
    string piec_znakow = "";
    int counter =0;
    while(coded_file_to_read.get(znak))
    {
        piec_znakow += znak;
        ++counter;
        if (counter == 5){
            un_coded_file << mapa_kod_odwrocony[piec_znakow];
            counter = 0;
            piec_znakow.clear();
        }
    }

    source.close();
    coded_file_to_read.close();
    un_coded_file.close();

    return 0;
}
