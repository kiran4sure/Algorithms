#include <bits/stdc++.h>
using namespace std;

class Button {
public:
    virtual void rightClick() const = 0;
    virtual void leftClick() const = 0;
};

class WindowsButton: public Button {
    void rightClick() const override {
        cout << "windows right click contains \n copy, paste with open terminal " << endl;
    }

    void leftClick() const override{
        cout << "Remains same for windows as well" << endl; 
    }
};

class LinuxButton: public Button {
    void rightClick() const override {
        cout << "Linux right click contains \n copy, paste thats all" << endl;
    }

    void leftClick() const override{
        cout << "Remains same for Linux as well" << endl; 
    }
};

class Dialog {

public:
    
    virtual Button *getButton() = 0;

    void location()
    {
        cout << "location is dynamic, depends on click position" << endl;
    }

    void size()
    {
        cout << "size can be altered dynamically" << endl;
    }

    void rClick()
    {
        getButton()->rightClick();
    }

    void lClick()
    {
        getButton()->leftClick();
    }

};


class WindowsDialog: public Dialog {
    Button *getButton() override {
        return new WindowsButton();
    }
};

class LinuxDialog: public Dialog {
    Button *getButton() override {
        return new LinuxButton();
    }
};


int main()
{
    WindowsDialog *wdn = new WindowsDialog();
    LinuxDialog *ldn = new LinuxDialog();
    wdn->lClick();
    wdn->rClick();
    ldn->lClick();
    ldn->rClick();
    return 0;
}
