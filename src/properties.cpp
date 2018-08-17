#include <properties.h>
#include <fstream>

using namespace std;

void properties::save()
{
    ofstream fout;
    fout.open("save-state.dat",ios::binary);
    fout.write((char*)this,sizeof(properties));
    fout.close();
}

void properties::load()
{
    properties p;
    ifstream fin;
    fin.open("save-state.dat");
    fin.read((char*)&p,sizeof(p));
    fin.close();
    *this = p;
}
