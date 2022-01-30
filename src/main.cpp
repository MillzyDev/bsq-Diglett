#include "main.hpp"

#include "Diglett.hpp"
using namespace Diglett;

#include "assets.hpp"


static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;

    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");

//#ifdef TESTS
    Register::RegisterLocales<Languages::EN>(ASSET_TO_XML(en_xml));
    Register::RegisterLocales<Languages::FR>(ASSET_TO_XML(fr_xml));
    Register::RegisterLocales<Languages::ES>(ASSET_TO_XML(es_xml));
    Register::RegisterLocales<Languages::DE>(ASSET_TO_XML(de_xml));
    Register::RegisterLocales<Languages::JA>(ASSET_TO_XML(ja_xml));
    Register::RegisterLocales<Languages::KO>(ASSET_TO_XML(ko_xml));

    getLogger().info("An Example English Localization: %s", LocalizationDocument::GetEN()->Get("Diglett:Tests:Test2").c_str());
    getLogger().info("An Example Spanish Localization: %s", LocalizationDocument::GetES()->Get("Diglett:Tests:Test2").c_str());
//#endif
}