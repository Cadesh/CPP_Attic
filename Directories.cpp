///@author Andre R
///@detail Two useful functions: get the absolute path of a file, list all direcotries inside a folder.

#include <iostream>
#include <dirent.h> //realpath
#include <stdlib.h>
#include <string>
#include <vector>

///This program tests two concepts:
/// 1 - How to capture am absolute path from a given folder
/// 2 - How to list all inner folders from a given folder

using namespace std;

//-------------------------------------------------
//-------------------------------------------------
string getAbsolutePath (const string &relPath) {

    string tmpStr = "";
    char* actualpath;

    actualpath = realpath(relPath.c_str(), NULL);
    if (actualpath != NULL)
    {
        tmpStr = actualpath;
    }

     free(actualpath);
     return tmpStr;
}
//--------------------------------------------------

//--------------------------------------------------
//--------------------------------------------------
vector<string> getSubFolders(const string & folderPath){
    vector <string> vecDirs;
    const char* path = folderPath.c_str();
    DIR *dir = opendir(path);
    struct dirent *entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
            vecDirs.push_back (entry->d_name);
            entry = readdir(dir);
    }
    closedir(dir);
    return vecDirs;
}
//---------------------------------------------------


int main()
{
    //Print an absolute path
    cout << "Get and absolute path." << endl;
    cout << getAbsolutePath("test1") << endl << endl;

    //List all subfolders from a given folder
    vector<string> dir = getSubFolders("test1");
    cout << "Print list of subfolders." << endl;
    for (string str: dir) {
        cout << str << endl;
    }

    return 0;
}
