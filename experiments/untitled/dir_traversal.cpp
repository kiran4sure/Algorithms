#include <dirent.h>
#include <iostream>
//#include <bits/stdc++.h>
#include <queue>

using namespace std;
int qmax = 0;
void show_dir_content(string path)
{
    struct dirent *de; // Pointer for directory entry
    queue<pair<string,string>> dir_q;
    // opendir() returns a pointer of DIR type.
    dir_q.push({path,"\t"});
    DIR *dr;
    while(!dir_q.empty())
    {
        int sz = dir_q.size();
        qmax = max(qmax,sz);
        path = dir_q.front().first;
        dr = opendir(path.c_str());
        string tab = dir_q.front().second;
//        cout << nm << endl;
        cout << tab << path << ":" << endl;
        dir_q.pop();
        while ((de = readdir(dr)) != NULL) // if we were able to read somehting from the directory
        {
            if(de->d_type != DT_DIR) // if the type is not directory just print it with blue
                cout << tab << "\t-" << de->d_name << endl;
            else
            if(de -> d_type == DT_DIR && strcmp(de->d_name,".")!=0 && strcmp(de->d_name,"..")!=0 ) // if it is a directory
            {
//                cout << de->d_name << endl;
                string cur_str = path + "/" +de->d_name;
                dir_q.push({cur_str,tab+"\t"});
            }
        }
        closedir(dr);
    }
}

int main(int argc, char **argv)
{

#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("input1.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("output1.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    show_dir_content(str);
    cout << "=============================" << endl;
    cout << "MAX = " << qmax << endl;
    return(0);
}
