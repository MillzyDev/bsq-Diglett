#include "localization.hpp"
#include "main.hpp"

#include "Polyglot/LocalizationImporter.hpp"
using namespace Polyglot;

void Diglett::registerLocalization(std::string csv) {
    csvs.push_back(csv);
}

void Diglett::registerLocalizationFromFile(std::string path) {
    std::string csv = readfile(path);
    registerLocalization(csv);
}

bool Diglett::refreshLocalization() {
    if (!ready) return false;
    else {
        LocalizationImporter::Refresh();
        return true;
    }
}