#include "Register.hpp"
#include "LocalizationDocument.hpp"
using namespace Diglett;

template<Format F, Languages L>
void Register::RegisterLocales(std::string file) {
    LocalizationDocument *ld;
    switch (L) {
        default:
        case Languages::EN:
            ld = LocalizationDocument::GetEN();
            break;
        case Languages::FR:
            ld = LocalizationDocument::GetFR();
            break;
        case Languages::ES:
            ld = LocalizationDocument::GetES();
            break;
        case Languages::DE:
            ld = LocalizationDocument::GetDE();
            break;
        case Languages::JA:
            ld = LocalizationDocument::GetJA();
            break;
        case Languages::KO:
            ld = LocalizationDocument::GetKO();
            break;
    }

    ld->AddLocalizations<F>(file);
}