#include "main.hpp"

#include "GlobalNamespace/QuestAppInit.hpp"
using namespace GlobalNamespace;

#include "Polyglot/LocalizationAsset.hpp"
#include "Polyglot/Localization.hpp"
#include "Polyglot/LocalizationImporter.hpp"
#include "Polyglot/GoogleDriveDownloadFormat.hpp"
using namespace Polyglot;

#include "UnityEngine/TextAsset.hpp"
using namespace UnityEngine;

#include "Register.cpp"
using namespace Diglett;

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

    getLogger().info("Installing hooks...");

    getLogger().info("Installed all hooks!");
}