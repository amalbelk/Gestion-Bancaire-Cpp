#ifndef COMPTEPROFESSIONNEL_H
#define COMPTEPROFESSIONNEL_H

#include "compte.h"

class CompteProfessionnel : public Compte {
private:
    std::string nomDelentreprise;
    std::string numeroSiret;

public:
    CompteProfessionnel(const std::string& rib,
                        const std::shared_ptr<Client>& client,
                        double solde,
                        const std::string& nomDelentreprise,
                        const std::string& numeroSiret);

    const std::string& getNomDelentreprise() const;
    const std::string& getNumeroSiret() const;

    bool retirer(double montant) override;
    void afficher() const override;
};

#endif
