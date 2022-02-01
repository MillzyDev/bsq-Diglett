# Diglett: Diglett: Easy Localization for Beat Saber


<p float="left">
  <p>
    Want to add localization to your Beat Saber mods? <br>    
    Don't wanna deal with the pain of using CSV and Polyglot?
    Then you should use <strong>Diglett</strong>                           
  </p>
  <img src="https://user-images.githubusercontent.com/64277238/151868295-0c690320-6333-4b74-90a6-c7003edb600f.png" alt="drawing" width="200"/>     
</p>

## Tutorial

Documentation can be found here.

### Index
- [Setup](#setup)
- [Creating a Localization File](#creating-a-localization-file)
  - [Create a JSON Localization File](#to-create-a-json-localization-file)
  - [Create an XML Localization File](#to-create-an-xml-localization-file)
  - [Creating Custom Localization Files](#creating-custom-localization-files)
- [Registering Localizations](#registering-localization-filesassets)
  - [Registering Custom Localizations](#registering-custom-localizations)
- [Getting Localizations from Key](#getting-localizations-from-key)

### Setup
The easiest way to load localization JSON and XML files, is using "Laurie's Fully™-Functional Objcopy CMake Script".
It can be found pinned in #quest-mod-dev in the BSMG. You can of course manually load the files from your ModData dir if you so wish, but I will not be going into that here.

Add the script to your CMakeLists.txt and include `assets.hpp` in your `main.cpp` file. (It doesnt matter if exists or not currently; it will be created when you build)

Install Diglett with `qpm-rust dependency add diglett` and `qpm-rust restore`

Include the header `Diglett/shared/Diglett.hpp` in your `main.cpp` file.



### Creating a Localization File

First, create a folder in the root for your project called `assets`.

You have two choices as to which file format you wish to create localizations in:
- XML
- JSON

I would recommend using JSON, but XML can be much more useful on larger projects where annotation may be needed on some localizations.

#### To create a JSON Localization File:

Create a file in assets depending on what language it is in, you will see a list of names for each language below:
- `en.json` - English
- `fr.json` - French
- `es.json` - Spanish
- `de.json` - German
- `ja.json` - Japanese
- `ko.json` - Korean

**You do not need to follow this format, but it is recommended to avoid confusion.**

In each JSON file, localizations should be formatted as such:
```json
{
  "localizationKey": "localization",
  "localizationKey2": "localization2"
}
```

**When creating a Localization Key, I recommend using one of the following formats:**
- `ModName:Group:Name` - E.g `Slogans:Buttons:Select`

or

- `MODNAME_GROUP_NAME` - E.g `SLOGANS_BUTTONS_SELECT`

Please be consistent with keys and only use one format in your mod to avoid confusion.

#### To create an XML Localization File:

As stated in the JSON, Create a file in assets depending on what language it is in, you will see a list of names for each language below:
- `en.xml` - English
- `fr.xml` - French
- `es.xml` - Spanish
- `de.xml` - German
- `ja.xml` - Japanese
- `ko.xml` - Korean

**You do not need to follow this format, but it is recommended to avoid confusion.**

In each XML file, localizations should be formatted as such:
```xml
<resources>
    <string name="localizationKey">localization</string>
    <string name="localizationKey2">localization2</string>
</resources>
```

XML files are great because they allow you to add additional data and comments without disrupting the localization. This can be useful in large collaborative projects, where clarity and communication between developers is important.
```xml
<resources>
   <string name="Slogans:Buttons:Select" 
           comment="Localization for select button in each slogan">
       Select
   </string>
    <!-- Localization for delete button in each slogan -->
    <string name="Slogans:Buttons:Delete">Delete</string>
</resources>
```

**When creating a Localization Key, I recommend using one of the following formats:**
- `ModName:Group:Name` - E.g `Slogans:Buttons:Select`

or

- `MODNAME_GROUP_NAME` - E.g `SLOGANS_BUTTONS_SELECT`

Please be consistent with keys and only use one format in your mod to avoid confusion.

### Creating Custom Localization Files

Creating custom localizations is almost exactly the same as creating regular localizations

I do recommend that you stick to the following naming convention: <br>
Please use the full name of the custom localization in the file like below:
- A custom LOLCAT localization would have a file created as either:
  - `lolcat.json`
  <br>
  or
  - `lolcat.xml`
- And a custom Pirate Speak localization would have a file created as either:
  - `pirate_speak.json`
  <br>
  or
  - `pirate_speak.xml`

The file contents would follow the same format as regular localizations

**JSON:**
```xml
<resources>
  <string name="CustomLangs:LOLCAT:Solo">lonleh kitteh</string>
  <string name="CustomLangs:LOLCAT:Multiplayer">i can haz frens</string>
</resources>
```

**XML:**
```json
{
  "CustomLangs:Pirate_Speak:Solo": "Swashbucklin'",
  "CustomLangs:Pirate_Peak:Multiplayer": "Play with ya mates"
}
```

### Registering Localization Files/Assets

Run `./build.ps1` in your project to compile the assets/files into the header.

Say we want to register our Localization "Document". Refer to the pseudocode example below.
```cpp
// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");
    
    Diglett::Register::RegisterLocales<Language>(LocalizationAsset)
    
    ...
}
```

We see that we register localizations in our `load()` function. 
`RegisterLocales` takes a Language template argument and `LocalizationAsset` is either a `rapidjson::MemoryStream` or a `char *` depending on the document format.

Laurie's asset script doesn't provide these data types, so we use a Macro that is included in `Register.hpp`, it should already be included in `Diglett.hpp`.

The macros are used for their appropriate formats:
```cpp
ASSET_TO_JSON(JsonAsset) // For JSON Documents
ASSET_TO_XML(XmlAsset) // For XML Documents`
```

Now, lets use these macros to register our localizations:
```cpp
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");
    
    // The asset name is the same as your localization file except '.' is replaced with '_'
    // So "en.json" becomes "en_json"
    Diglett::Register::RegisterLocales<Language::Engish>(ASSET_TO_JSON(en_json));
    
    // Same is true for XML
    // "es.xml" becomes "es_xml"
    Diglett::Register::RegisterLocales<Language::Spanish>(ASSET_TO_JSON(es_xml));
    
    ...
}
```

#### Registering Custom Localizations

Registering Localizations is the same as registering regular localizations, however there are some differences:
- Custom Localizations are registered differently
- `RegisterCustomLocales()` has a different template argument

Custom Localizations are registered into a map of custom localizations rather than each assigned their own property in `LocalizationDocument`

Actually Registering the custom locales is straight forward:

```cpp
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering custom locales");
    
    // Instead of using the languages enumerator for selecting the language,
    // the TArg takes an std::string value instead, this will be used to find your language manually.
    Diglett::Register::RegisterCustomLocales<"LOLCAT">(ASSET_TO_JSON(lolcat_json));

    Diglett::Register::RegisterCustomLocales<"Pirate_Speak">(ASSET_TO_XML(pirate_speak_xml));
    
    ...
}
```

### Getting Localizations from Key

There are two for getting localizations from keys. Getting from specific languages and Getting from the selected language.

Getting localizations is fairly straight forward.
```cpp
#include "Diglett.hpp"

...

Localization::GetEN()->Get("Slogans:Buttons:Select"); 
// Returns the English localization for the key "Slogans:Buttons:Select"

Localization::GetSelected()->Get("Slogans:Buttons:Select");
// Return the localization for the key "Slogans:Buttons:Select" 
// but for whatever language Polyglot currently has selected
```

## Credits

* [zoller27osu](https://github.com/zoller27osu), [Sc2ad](https://github.com/Sc2ad) and [jakibaki](https://github.com/jakibaki) - [beatsaber-hook](https://github.com/sc2ad/beatsaber-hook)
* [raftario](https://github.com/raftario)
* [Lauriethefish](https://github.com/Lauriethefish), [danrouse](https://github.com/danrouse) and [Bobby Shmurner](https://github.com/BobbyShmurner) for [this template](https://github.com/Lauriethefish/quest-mod-template)
