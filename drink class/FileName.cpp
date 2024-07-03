#include <iostream>
#include <string>
#include<vector>

using namespace std;

class gida
{
protected:
    string name;
    string tur;
    int kalori;

public:
    gida() {}

    gida(string name, string tur, int kalori)
    {
        this->name = name;
        this->tur = tur;
        this->kalori = kalori;
    }

    ~gida() { cout << name << " yok edildi..." << endl; }

    void setAll(string name, string tur, int kalori)
    {
        this->name = name;
        this->tur = tur;
        this->kalori = kalori;
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    string getTur() { return tur; }
    void setTur(string tur) { this->tur = tur; }

    int getKalori() { return kalori; }
    void setKalori(int kalori) { this->kalori = kalori; }

    virtual void display()
    {
        cout << "Gidanin display metoduyum ve ..." << endl;
        cout << "Ad   : " << name << endl;
        cout << "Tur  : " << tur << endl;
        cout << "Kalori : " << kalori << endl;
        cout << "_\n" << endl;
    }
};

class drink :public gida
{
private:
    string marka;
    int hacim;
    string sicak;

public:
    drink() { name = "Default Icecek"; tur = "Default Tur"; marka = "Default Marka"; hacim = 100; sicak = "soguk"; kalori = 0; }

    drink(string name, string tur, string marka, int hacim, string sicak, int kalori)
    {
        this->name = name;
        this->tur = tur;
        this->marka = marka;
        this->hacim = hacim;
        this->sicak = sicak;
        this->kalori = kalori;
    }

    ~drink() { cout << marka << " " << name << " yok edildi" << endl; }

    void setAll(string name, string tur, string marka, int hacim, string sicak, int kalori)
    {
        this->name = name;
        this->tur = tur;
        this->marka = marka;
        this->hacim = hacim;
        this->sicak = sicak;
        this->kalori = kalori;
    }

    string getMarka() { return marka; }
    void setMarka(string marka) { this->marka = marka; }

    int getHacim() { return hacim; }
    void setHacim(int hacim) { this->hacim = hacim; }

    string getSicak() { return sicak; }
    void setSicak(string sicak) { this->sicak = sicak; }

    void display()
    {
        cout << "Ad   : " << name << endl;
        cout << "Tur  : " << tur << endl;
        cout << "Marka : " << marka << endl;
        cout << "Hacim : " << hacim << endl;
        cout << "Sicak : " << sicak << endl;
        cout << "Kalori : " << kalori << endl;
    }
};



int main()
{
    gida g1;
    gida g2("Yemek", "Kati Gida", 90);
    drink meyveSuyu;
    drink kola("Cola", "Asitli Icecek", "Pepsi", 330, "Soguk", 200);

    meyveSuyu.setAll("Meyve Suyu", "Meyve Konsantreli Icecek", "Cappy", 330, "Soguk", 150);
    kola.setKalori(42);

    vector<gida> gidaVektoru;

    gidaVektoru.push_back(g1);
    gidaVektoru.push_back(g2);
    gidaVektoru.push_back(meyveSuyu);
    gidaVektoru.push_back(kola);

    for (int i = 0; i < gidaVektoru.size(); i++)
        gidaVektoru[i].display();

    cout << "Kolanýn 100ml hacimdeki kalori miktari : " << kola.getKalori() << endl; 

    return 0;
}
