![Logo](./resources/logo.png)

# SkyVis &middot; [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com) [![GitHub license](https://img.shields.io/badge/license-GPL-blue.svg?style=flat-square)](https://github.com/arturianec100/skyvis/blob/master/LICENSE)

An IDE for visual programming.

## Installing / Getting started

To compile it you should have qmake, Qt5 (Core, Widgets, Xml) and C++ compiler. On Windows or Mac it's better just to install Qt Creator and compile there.

On GNU/Linux you also can:
```
sudo apt-get install build-essential libfontconfig1 mesa-common-dev libgl qt5base-dev
```
Or install these packages with your package manager.

## Developing

### Built With
Qt5.

### Documentation

To create local documentation you need to have doxygen
```
sudo apt-get doxygen
sudo apt-get doxygen-gui #if you wanna use GUI
```

#### Cli way

To generate documentation via cli application run this in project file:
```
doxygen Doxyfile
```
Now you have documentation in "Docs" file. Open Docs/html/index.html by any browser.

#### GUI way

Run gui application
```
doxywizard Doxyfile
```
Now go to Run tab and click on button "Run doxygen", when it ready choose "Show html"

### Building

Just open project in Qt Creator and click "Build" or "Run" button.

On GNU/Linux you also can:
```
cd skyvis
qmake
make
```
On Windows executable file must be placed in the folder with Qt dll's.

### Deploying / Publishing
TODO

## Versioning
TODO

## Configuration
TODO

## Tests
TODO

## Style guide
Qt C++ style.

## Licensing
GNU GPLv3
