#include <iostream>
#include <string>
using namespace std;

class RezervareHotel {
private:
    int idRezervare;
    string numeClient;
    string tipCamera;
    int numarNopti;
    double pretNoapte;

public:
    
    RezervareHotel() {
        idRezervare = 0;
        numeClient = "Necunoscut";
        tipCamera = "Standard";
        numarNopti = 1;
        pretNoapte = 100;
    }

    
    RezervareHotel(int id, string nume, string camera, int nopti, double pret) {
        idRezervare = id;
        numeClient = nume;
        tipCamera = camera;
        numarNopti = nopti;
        pretNoapte = pret;
    }

    
    RezervareHotel(const RezervareHotel& r) {
        idRezervare = r.idRezervare;
        numeClient = r.numeClient;
        tipCamera = r.tipCamera;
        numarNopti = r.numarNopti;
        pretNoapte = r.pretNoapte;
    }

   
    ~RezervareHotel() {
        cout << "Rezervarea a fost stearsa." << endl;
    }

    
    double calculPret() {
        return numarNopti * pretNoapte;
    }

    void prelungireSejur(int nopti) {
        numarNopti += nopti;
    }

    void modificareCamera(string cameraNoua) {
        tipCamera = cameraNoua;
    }

    void afisareRezervare() {
        cout << "ID: " << idRezervare << endl;
        cout << "Client: " << numeClient << endl;
        cout << "Camera: " << tipCamera << endl;
        cout << "Nopti: " << numarNopti << endl;
        cout << "Pret/noapte: " << pretNoapte << endl;
        cout << "Pret total: " << calculPret() << endl;
    }

    double getPretTotal() {
        return calculPret();
    }
};

int main() {
    RezervareHotel r1;
    RezervareHotel r2(1, "Ion Chistruga", "Deluxe", 3, 250);

    r1.afisareRezervare();
    cout << endl;

    r2.afisareRezervare();
    r2.prelungireSejur(2);

    cout << "Dupa prelungire:" << endl;
    r2.afisareRezervare();

    return 0;
}
