#include "main.hpp"

#include "Diglett.hpp"

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

    Diglett::Register::RegisterLocales<Language::English>(getLogger(), ASSET_TO_JSON(en_json));
    Diglett::Register::RegisterLocales<Language::English>(getLogger(), ASSET_TO_XML(en_xml));

    Diglett::Register::RegisterLocales<Language::French>(getLogger(), ASSET_TO_JSON(fr_json));
    Diglett::Register::RegisterLocales<Language::French>(getLogger(), ASSET_TO_XML(fr_xml));

    Diglett::Register::RegisterLocales<Language::Spanish>(getLogger(), ASSET_TO_JSON(es_json));
    Diglett::Register::RegisterLocales<Language::Spanish>(getLogger(), ASSET_TO_XML(es_xml));

    Diglett::Register::RegisterLocales<Language::German>(getLogger(), ASSET_TO_JSON(de_json));
    Diglett::Register::RegisterLocales<Language::German>(getLogger(), ASSET_TO_XML(de_xml));

    Diglett::Register::RegisterLocales<Language::Japanese>(getLogger(), ASSET_TO_JSON(ja_json));
    Diglett::Register::RegisterLocales<Language::Japanese>(getLogger(), ASSET_TO_XML(ja_xml));

    Diglett::Register::RegisterLocales<Language::Korean>(getLogger(), ASSET_TO_JSON(ko_json));
    Diglett::Register::RegisterLocales<Language::Korean>(getLogger(), ASSET_TO_XML(ko_xml));

    getLogger().info("An Example English Localization: %s", to_utf8(Localization::GetEN()->Get("Diglett:Tests:Test1")).c_str());
    getLogger().info("An Example English Localization: %s", to_utf8(Localization::GetEN()->Get("Diglett:Tests:Test2")).c_str());

    getLogger().info("An Example Spanish Localization: %s", to_utf8(Localization::GetES()->Get("Diglett:Tests:Test1")).c_str());
    getLogger().info("An Example Spanish Localization: %s", to_utf8(Localization::GetES()->Get("Diglett:Tests:Test2")).c_str());
}