#include <iostream>
#include <vector>
#include <string>

using namespace std;

class player;

enum class status{win,  completed};
enum class stat{valid, notValid};

class board{
    player *p1;
    player *p2;
    vector<vector<char>> *brd;

//    bool isEmpty()
//    {
//        bool ret = true;
//
//        for(auto a: *brd)
//        {
//            for(char b: a)
//            {
//                if
//            }
//        }
//    }
public:
    board(player *p1, player *p2) : p1(p1), p2(p2) {
        vector<vector<char>> b(3, vector(3,'0'));
        brd = &b;
    }

    void display()
    {

    }

    stat isValid(player *p, int pos)
    {
        stat st = stat::valid;

        if(pos < 1 || pos > brd->size() * brd[0].size() ||  )
        {
            st = stat::notValid;
        }else if(p->getSymbol())

        return st;
    }

    status validate(int pos)
    {

    }

    void start()
    {
        while()


    }
};

class player{
    char symbol;
    string name;
    board *bd;
public:
    player(char sym, string name, board *b):symbol(sym), name(name), bd(b){}

    int move(int p)
    {
        int pos;
        do{
            cout << this->name << ":" << endl;
            cin >> pos;
        }while(bd->isValid(pos) == 0);

        bd->display();
    }

    char getSymbol()
    {
        return symbol;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
