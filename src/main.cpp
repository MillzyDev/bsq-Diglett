#include "main.hpp"

#include "assets.hpp"

#include "Register.hpp"
#include "Conversions.hpp"

#include "Tests/TestViewController.hpp"

#include "custom-types/shared/register.hpp"
#include "questui/shared/QuestUI.hpp"

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
[[maybe_unused]]
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;

    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
[[maybe_unused]]
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");

    Diglett::RegisterAsset(ASSET_TO_STR(en_xml), Diglett::Language::ENGLISH);
    Diglett::RegisterAsset(ASSET_TO_STR(fr_xml), Diglett::Language::FRENCH);
    Diglett::RegisterAsset(ASSET_TO_STR(es_xml), Diglett::Language::SPANISH);
    Diglett::RegisterAsset(ASSET_TO_STR(de_xml), Diglett::Language::GERMAN);
    Diglett::RegisterAsset(ASSET_TO_STR(ja_xml), Diglett::Language::JAPANESE);
    Diglett::RegisterAsset(ASSET_TO_STR(ko_xml), Diglett::Language::KOREAN);

    custom_types::Register::AutoRegister();

    QuestUI::Register::RegisterMainMenuModSettingsViewController<Diglett::Tests::TestViewController *>(modInfo);
}