#include <iostream>
#include <map>

using namespace std;

struct coordinates
{
    float x1;
    float x2;
    float y1;
    float y2;
};

class box
{
public:
    coordinates *c;
    float boxNum;
    
    box(coordinates *c1, float box_num=0)
    {
        // c = new coordinates();
        // c->x1 = c1->x1;
        // c->x2 = c1->x2;
        // c->y1 = c1->y1;
        // c->y2 = c1->y2;
        c = c1;
        boxNum = box_num;
    }
    
    void print()
    {
        cout << "=======================" << endl;
        cout << "x1=" << c->x1 << " ," << "x2=" << c->x2 << " ,"<< "y1=" << c->y1 << " ,"<< "y2=" << c->y2 << endl;
        cout << "boxNum = " << boxNum << endl;
    }
};



class placer
{
public:
    //map to maintain list of boxes
    map<float, box*> lst;
    //length of each box
    float boxLength = 5;
    //withd between boxes
    float interWidth = 5.0;
    //total width
    float total_witdth = 100;

    /*
        validate if additon of new box will fit in the given space,
        if yes, re-calculate and adjust the interWidth
        else return false
    */
    bool validate()
    {
        //calculation to adjust with and if it fits in
        int bx_size = lst.size()+1;
        float t_interWidth = (this->total_witdth - (bx_size*this->boxLength))/(bx_size+1);
        if(t_interWidth > 0.0)
        {
            this->interWidth = t_interWidth;
            return true;
        }
        return false;
    }

    void getNewBoxCordinates(box *afterBox=nullptr, coordinates *c1=nullptr, int BorA=1)
    {
        if(afterBox==nullptr)
        {
            //first cordinates
            c1->x1 = this->interWidth;
            c1->x2 = c1->x1+this->boxLength;
            c1->y1 = 0;
            c1->y2 = 0;
        }
        else if(BorA == 1)
        {
            //next cordinates
            c1->x1 = afterBox->c->x2+this->interWidth;
            c1->x2 = c1->x1+this->boxLength;
            c1->y1 = 0;
            c1->y2 = 0;
        }
        else
        {
            //next cordinates
            c1->x2 = afterBox->c->x1-this->interWidth;
            c1->x1 = c1->x2-this->boxLength;
            c1->y1 = 0;
            c1->y2 = 0;
        }
    }
    /*
        get the last box's number, increment by one and append
        the new box to end of the list
    */
    void _append()
    {
        box *last = this->lst.rbegin()->second;
        float newBoxNum = last->boxNum+1;
        coordinates *c = new coordinates();
        getNewBoxCordinates(last, c);
        lst.insert({c->x2, new box(c,newBoxNum)}); 
    }

    /*
        check weather the given position falls into the area
        of the given box, if yes return false.
        else return true.
    */
    bool _PositionInsideBox(box *b, float position)
    {
        if((position >=  b->c->x1) && (position <= b->c->x2))
        {
            return false;
        }

        return true;
    }

    void _print(char c, int num)
    {
        for(int i=0; i<num; i++)
            cout << c;
    }
    
    void _printBox(float num)
    {
        cout << '|';
        _print(' ', this->boxLength/2);
        cout << num;
        _print(' ', this->boxLength/2);
        cout << '|';
    }
    
    void render()
    {
        char space = '-';
        _print(space,this->interWidth);
        for(auto i=lst.begin(); i!=lst.end(); i++)
        {
            box *bx = i->second;
            _printBox(bx->boxNum);
            _print(space,this->interWidth);
        }
        cout << endl;
    }
    
    void printAddress()
    {
        for(auto i=lst.begin(); i!=lst.end(); i++)
        {
            i->second->print();
        }
    }

    // void correct_coordinates(map<float, box*>::iterator itr)
    // {
    //     box *b = itr->second;
    //     b->c->x1 += boxLength+interWidth;
    //     b->c->x2 = b->c->x1+boxLength; 
    // }

    void correct_list()
    {
        int x1 = 0;
       map<float, box*> new_lst;

        for(auto itr = lst.begin(); itr!=lst.end(); itr++)
        {
            itr->second->c->x1 =   x1 = x1+this->interWidth;
            itr->second->c->x2 =   x1 = x1+this->boxLength;
            new_lst.insert({itr->second->c->x2, itr->second});
        }

        this->lst = new_lst;
    }

    /*
        add the new box based on the given position,
        if position is -1 then append a new box to end
        else validate the positon, if its valid, insert
        the new box with new value to the list
    */
    bool add(float position=-1.0)
    {
        bool status = true;
        if(!validate())
                return false;
                
        if(position < -1 || position > this->total_witdth)
            return false;

        if(lst.empty())
        {
            coordinates *c = new coordinates();
            getNewBoxCordinates(nullptr,c);
            lst.insert({c->x2, new box(c,1)});
            correct_list();
            return status;
        }

        if(position == -1.0)
        {
           _append();
            //return status;
        }
        else
        {
            auto mp = lst.lower_bound(position);
            if(mp == lst.end())
            {
                _append();
            }
            else
            {
            
                box *InsertBeforeBox = mp->second;
                
                if(_PositionInsideBox(InsertBeforeBox, position) == false)
                    return true;
                
                if(InsertBeforeBox == lst.begin()->second)
                {
                    float newBoxNum = InsertBeforeBox->boxNum - 1.0;
                    coordinates *c = new coordinates();
                    getNewBoxCordinates(nullptr,c);
                    lst.insert({c->x2, new box(c,newBoxNum)});
                }
                else
                {
                    box *InsertAfterBox = prev(mp)->second;
                    float newBoxNum = (InsertBeforeBox->boxNum + InsertAfterBox->boxNum)/2.0;
                    coordinates *c = new coordinates();
                    getNewBoxCordinates(InsertAfterBox,c);
                    lst.insert({c->x2, new box(c,newBoxNum)});
                }
            }
        }
            correct_list();

        return status;
    }
};



int main()
{
    placer *pl = new placer();
    pl->add();
    pl->add();
    pl->add();
    pl->add();
    pl->add();
    pl->add();
    pl->add();
    pl->add(5);
    pl->add();
    pl->add();
    pl->add();
    pl->add(73);
    pl->add(49);
    // pl->add(1);
    // pl->add(1);
    // pl->add(53);
    // pl->add(99);


    // pl->add(105);
    
    pl->render();
    // pl->printAddress();
    

    return 0;
}

