#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Abstract base class declared by framework */
class Document
{
public:
    Document(string fn)
    {
        name = fn;
    }
    virtual void Open() = 0;
    virtual void Close() = 0;
    string GetName()
    {
        return name;
    }
private:
    string name;
};

/* Concrete derived class defined by client */
class MyDocument: public Document
{
public:
    MyDocument(string fn): Document(fn){}
    void Open()
    {
        cout << "Opening : " << GetName() << endl;
    }
    void Close()
    {
        cout << "Closing : " << GetName() << endl;
    }
};

/* Framework declaration */
class Application
{
public:
    Application(): _index(0)
    {
        cout << "Application: ctor" << endl;
    }
    /* The client will call this "entry point" of the framework */
    void NewDocument(string name)
    {
        cout << "Application: NewDocument()" << endl;
        /* Framework calls the "hole" reserved for client customization */
        _docs[_index] = CreateDocument(name);
        _docs[_index++]->Open();
    }
    void OpenDocument(){}
    void ReportDocs();
    /* Framework declares a "hole" for the client to customize */
    virtual Document *CreateDocument(string) = 0;
private:
    int _index;
    /* Framework uses Document's base class */
    Document *_docs[10];
};

void Application::ReportDocs()
{
    cout << "Application: ReportDocs()" << endl;
    for (int i = 0; i < _index; i++)
        cout << "   " << _docs[i]->GetName() << endl;
}

/* Customization of framework defined by client */
class MyApplication: public Application
{
public:
    MyApplication()
    {
        cout << "MyApplication: ctor" << endl;
    }
    /* Client defines Framework's "hole" */
    Document *CreateDocument(string fn)
    {
        cout << "   MyApplication: Creating document for: " << fn << endl;
        return new MyDocument(fn);
    }
};

int main()
{
    /* Client's customization of the Framework */
    MyApplication myApp;

    myApp.NewDocument("kiran");
    myApp.NewDocument("kishor");
    myApp.NewDocument("mom");
    myApp.NewDocument("dad");
    myApp.NewDocument("prapulla");
    myApp.NewDocument("Arya");
    myApp.NewDocument("prasad");
    myApp.NewDocument("Atthe");
    myApp.NewDocument("Mava");
    myApp.NewDocument("Prathiba");
    myApp.ReportDocs();
}