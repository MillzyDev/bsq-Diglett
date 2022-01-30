#include "main.hpp"

#ifdef TESTS
#include "Diglett.hpp"
using namespace Diglett;

#include "assets.hpp"
#endif


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

#ifdef TESTS
    Register::RegisterLocales<Languages::EN>(ASSET_TO_JSON(en_json));
    Register::RegisterLocales<Languages::FR>(ASSET_TO_JSON(fr_json));
    Register::RegisterLocales<Languages::ES>(ASSET_TO_JSON(es_json));
    Register::RegisterLocales<Languages::DE>(ASSET_TO_JSON(de_json));
    Register::RegisterLocales<Languages::JA>(ASSET_TO_JSON(ja_json));
    Register::RegisterLocales<Languages::KO>(ASSET_TO_JSON(ko_json));

    getLogger().info("%s", LocalizationDocument::GetEN()["Diglett:Tests:Test1"].c_str());
    getLogger().info("%s", LocalizationDocument::GetJA()["Diglett:Tests:Test1"].c_str());
#endif
}