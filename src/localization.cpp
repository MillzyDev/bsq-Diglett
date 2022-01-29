#include "localization.hpp"
#include "main.hpp"

#include "Polyglot/LocalizationImporter.hpp"
using namespace Polyglot;

void DiGlott::registerLocalization(std::string csv) {
    csvs.push_back(csv);
}

void DiGlott::registerLocalizationFromFile(std::string path) {
    std::string csv = readfile(path);
    registerLocalization(csv);
}

bool DiGlott::refreshLocalization() {
    if (!ready) return false;
    else {
        LocalizationImporter::Refresh();
        return true;
    }
}