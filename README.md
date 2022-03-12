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
  - [Create an XML Localization File](#to-create-an-xml-localization-file)
- [Registering Localizations](#registering-localization-filesassets)
- [Getting Localizations from Key](#getting-localizations-from-key)

### Setup
The easiest way to load localization JSON and XML files, is using "Laurie's Fully™-Functional Objcopy CMake Script".
It can be found pinned in #quest-mod-dev in the BSMG. You can of course manually load the files from your ModData dir if you so wish, but I will not be going into that here.

Add the script to your CMakeLists.txt and include `assets.hpp` in your `main.cpp` file. (It doesnt matter if exists or not currently; it will be created when you build)

Install Diglett with `qpm-rust dependency add diglett` and `qpm-rust restore`

Include the header `Diglett/shared/Diglett.hpp` in your `main.cpp` file.



### Creating a Localization File

First, create a folder in the root for your project called `assets`.

Localization files MUST be XML.

XML can be much more useful on larger projects where annotation may be needed on some localizations.

#### To create an XML Localization File:

Create a file in assets depending on what language it is in, you will see a list of names for each language below:
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

### Registering Localization Files/Assets

Run `./build.ps1` in your project to compile the assets/files into the header.

Say we want to register our Localization "Document". Refer to the pseudocode example below.
```cpp
// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");
    
    Diglett::RegisterAsset(ASSET_TO_STR(en_xml), Diglett::Language::ENGLISH);
    
    ...
}
```

We see that we register localizations in our `load()` function. 
`RegisterAsset` takes `LocalizationAsset` and `Language` as arguments. Whilst the `ASSET_TO_STR` macro does not construct a `LocalizationAsset` the `string_view` is does insert is implicitly converted to a `Localization` asset instance.

Laurie's asset script doesn't provide these data types, so we use a Macro that is included in `Register.hpp`, it should already be included in `Diglett.hpp`.

Now, lets use these macros to register our localizations:
```cpp
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Registering locales");
    
    // The asset name is the same as your localization file except '.' is replaced with '_'
    // So "en.xml" becomes "en_xml"
    Diglett::Register::RegisterLocales(ASSET_TO_STR(en_json), Diglett::Language::ENGLISH);
    ...
}
```

### Getting Localizations from Key

There are two for getting localizations from keys. Getting from specific languages and Getting from the selected language.

Getting localizations is fairly straight forward.
```cpp
#include "Localization.hpp"

...

Diglett::Localization::get_instance()->get("Slogans:Buttons:Select", Diglett::Languages::ENGLISH);
```
Here we use the `Localization` class to get our localized string. You do need to specify the language, however.

Using this same method for each text can be long and unnecessary, so we can use the `getLocales()` method:

```cpp
auto locales = Diglett::Localization::get_instance()->getLocales(Diglett::Languages::ENGLISH);

auto selectText = StringW(locales["Slogans:Buttons:Select"]);
auto deleteText = StringW(locales["Slogans:Buttons:Delete"]);
```

NOTE: When constructing a `StringW` to use or calling `Localization::get()`, please use the text **immediately** due to the possibility of the StringW being GC'd. Storing it in a variable here is for purely demonstration purposes.

You will notice that you have to declare what language you wish to use in both examples. But when doing this in a practical mod, you want to automatically get the selected language.

`Utils.hpp` has a method for this. Add it to your includes, and you can simply do `Diglett::getSelectedLanguage()`. This method uses Polyglot to find whatever language is selected.

```cpp
auto locales = Diglett::Localization::get_instance()->getLocales(Diglett::getSelectedLanguage());

auto selectText = StringW(locales["Slogans:Buttons:Select"]);
auto deleteText = StringW(locales["Slogans:Buttons:Delete"]);
```

## Credits

* [zoller27osu](https://github.com/zoller27osu), [Sc2ad](https://github.com/Sc2ad) and [jakibaki](https://github.com/jakibaki) - [beatsaber-hook](https://github.com/sc2ad/beatsaber-hook)
* [raftario](https://github.com/raftario)
* [Lauriethefish](https://github.com/Lauriethefish), [danrouse](https://github.com/danrouse) and [Bobby Shmurner](https://github.com/BobbyShmurner) for [this template](https://github.com/Lauriethefish/quest-mod-template)
