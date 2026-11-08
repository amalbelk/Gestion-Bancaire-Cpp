#include "CompteProfessionnel.h"
#include <iostream>
#include <stdexcept>
using namespace std;

CompteProfessionnel::CompteProfessionnel(
    const string& rib, const shared_ptr<Client>& client, double solde,
    const string& nomDelentreprise, const string& numeroSiret)
    : Compte(rib, client, solde),
      nomDelentreprise(nomDelentreprise),
      numeroSiret(numeroSiret) {
    if (nomDelentreprise.empty() || numeroSiret.empty()) {
        throw invalid_argument(
            "Le nom de l'entreprise et le numero SIRET sont obligatoires.");
    }
}

const string& CompteProfessionnel::getNomDelentreprise() const {
    return nomDelentreprise;
}

const string& CompteProfessionnel::getNumeroSiret() const {
    return numeroSiret;
}

bool CompteProfessionnel::retirer(double montant) {
    return Compte::retirer(montant);
}

void CompteProfessionnel::afficher() const {
    cout << "--- Compte Professionnel ---" << endl;
    Compte::afficher();
    cout << "Entreprise : " << nomDelentreprise << endl;
    cout << "Numero SIRET : " << numeroSiret << endl;
}
