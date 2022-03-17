// THIS HEADER IS FOR DOXYGEN DOCUMENTATION GENERATION ONLY
// DO NOT INCLUDE

/*! \mainpage
 *
 *   \section intro_sec Introduction
 *   Want to add localization to your Beat Saber mods?
 *   Don't wanna deal with the pain of using CSV and Polyglot? Then you should use Diglett
 *
 *   \section setup_sec Setup
 *   The easiest way to load localization JSON and XML files, is using "Laurie's Fully™-Functional Objcopy CMake Script". It can be found pinned in #quest-mod-dev in the BSMG. You can of course manually load the files from your ModData dir if you so wish, but I will not be going into that here.
 *
 *   Add the script to your CMakeLists.txt and include `assets.hpp` in your `main.cpp` file. (It doesnt matter if exists or not currently; it will be created when you build)
 *   Install Diglett with `qpm-rust dependency add diglett` and  `qpm-rust restore`
 *
 *   \section file_sec Creating a Localization File
 *   First, create a folder in the root for your project called `assets/`.
 *   Localization files MUST be XML.
 *   XML can be much more useful on larger projects where annotation may be needed on some localizations.
 *
 *   To create an XML Localization File:
 *   Create a file in `assets/`. The filename should depend on what language the localization is in.
 *
 *   You will see a list of names for each language below:
 *   - `en.xm` - English
 *   - `fr.xml` - French
 *   - `es.xml` - Spanish
 *   - `de.xml` - German
 *   - `ja.xml` - Japanese
 *   - `ko.xml` - Korean
 *
 *   You do not need to follow this format but it is recommended to avoid confusion.
 *
 *   In each XML file, localizations should be formatted as such:
 *   \code
 *   <resources>
 *      <string name="localizationKey">localization</string>
 *      <string name="localizationKey2">localization2</string>
 *   </resources>
 *   \endcode
 *
 *   XML files are great because they allow us to add additional data and comments without disrupting the actual localization.
 *   This can be useful in large collaborative projects, where clarity and communication between developers is important.
 *
 *   \code
 *   <resources>
 *      <!-- Localization for delete button in each slogan -->
 *      <string name="Slogans:Buttons:Delete">Delete</string>
 *   </resources>
 *   \endcode
 *
 *   When creating a localization key, I recommend using on eof the following formats:
 *   - `ModName:Group:Name` - E.g. `Diglett:Tests:Test`
 *   or
 *   - `MODNAME_GROUP_NAME` - E.g. `DIGLETT_TESTS_TEST`
 *
 *   Please be consistent when naming keys and only use one format in your mod to avoid confusion.
 *
 *   \section register_sec Registering Localization Files/Assets
 *   run `./build.ps1`
 *   Say we want to register our Localization Asset. Refer to the example below.
 *   \code
 *   // Called later on in the game loading - a good time to install function hooks
 *   extern "C" void load() {
 *     il2cpp_functions::Init();
 *
 *     getLogger().info("Registering locales");
 *
 *     Diglett::RegisterAsset(ASSET_TO_STR(en_xml), Diglett::Language::ENGLISH);
 *
 *     ...
 *   }
 *   \endcode
 *   We see that we register localization in our `load()` function.
 *   `RegisterAsset()` takes a `LocalizationAsset` and a `Language` as it's arguments.
 *   Whilst the `ASSET_TO_STR` macro does not construct a `LocalizationAsset`, the `string_view` it does return is implicitly converted to a `LocalizationAsset` instance.
 *
 *   \section getting_sec Getting Localizations from Key
 *   There are two ways to get localizations from keys: With specific languages and with the selected language.
 *   \subsection getting_spec_sec Getting from Specific Languages
 *   We use the `Localization` class to get out string since it does basically everything.
 *   \code
 *   auto localization = Diglett::Localization::get_instance();
 *
 *   auto testText = localization->get("Diglett::Tests:Test", Diglett::Language::English);
 *   \endcode
 *   NOTE: You should use the created string immediately due to the StringW being GCable. Storing it in a variable here is for purely demonstration purposes.
 *
 *   Specifying what language to use can be annoying and tedious. Realistically you want this to be handled automatically and for the selected language in Beat Saber to be used.
 *
 *   \subsection getting_auto_sec Getting from Selected Language
 *   You could feed the previous `get()` method with `Diglett::getSelectedLanguage` but thats long. So instead you can just give `get()` the key and nothing else.
 *
 *   \code
 *   auto localization = Diglett::Localization::get_instance();
 *
 *   auto testText = localization->get("Diglett::Tests:Test");
 *   \endcode
 */