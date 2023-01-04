
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "numeric/functions.hpp"
#include "numeric/longest.hpp"
#include <algorithm>
using namespace std;



char letters[]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','#','1','2','3','4','5','6','7','8','9'};
int getIndex(char k){
    int n = sizeof(letters)/sizeof(letters[0]);
    auto itr = find(letters,letters+n,k);
    return (distance(letters,itr)+1);
}

struct elGamalE {
private:
    ulongest y = 0, g = 0, p = 0;
    
public:
    elGamalE(ulongest y, ulongest g, ulongest p) {
        this->y = y;
        this->g = g;
        this->p = p;
    }
    
    pair<ulongest, ulongest> encrypt(ulongest message) {
        ulongest k = getEasy(p - 1);
        return pair<ulongest, ulongest>(pow(g, p, k), (pow(y, p, k) * message) % p);
    }
};

struct elGamalD {
private:
    ulongest x = 0, p = 0;
    
public:
    elGamalD(ulongest x, ulongest p) {
        this->x = x;
        this->p = p;
    }
    
    ulongest decrypt(pair<ulongest, ulongest> message) {
        return (message.second * pow(message.first, p, p - 1 - x)) % p;
    }
};



pair<elGamalE, elGamalD> elGamalGenerate(ulongest p) {
    ulongest g = getG(p);
    ulongest x = rand() % (p.toInt() - 1) + 1;
    ulongest y = pow(g, p, x);

    return pair<elGamalE, elGamalD>(elGamalE(y, g, p), elGamalD(x, p));
}


void elGamalExample(ulongest message, char A) {
    ulongest p = 1013;
    
    pair<elGamalE, elGamalD> elGamal = elGamalGenerate(p);

    cout << "Msg: " <<A<< endl;

    pair<ulongest, ulongest> encryptedMessage = elGamal.first.encrypt(message);
    cout << "Encrypted msg: (" << encryptedMessage.first.toInt() << ", " << encryptedMessage.second.toInt() << ")" << endl;
    
    ulongest decryptedMessage = elGamal.second.decrypt(encryptedMessage);
    cout << "Decrypted msg: " << char(letters[decryptedMessage.toInt()-1]) << endl;
}

int main() {
    char A;
    cout<<"Inpurt letter: "<<endl;
    cin>>A;

    long long m = getIndex(A);
    ulongest mes = ulongest(m);
    elGamalExample(mes,A);
}
