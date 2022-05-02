# Ghost
![](Images/Logo.jpg)

An amazing watch.

# Functions and tasks
- [ ] Basic software framework.
  - [X] Support lvgl.
  - [X] Ghost Package manager.
  - [X] Ghost Clock.
  - [X] Ghost Thread.
  - [X] Ghost File system.
  - [ ] Ghost safe lvgl.
  - [ ] lua interpreter.
  - [ ] Power manager framework.
  
- [ ] Basic function realization.
  - [ ] Basic clock function.
- [ ] PCB and BOM.
- [ ] Mechanical structure.

# Build
## Windows Simulator
```Bash
git clone https://github.com/h13-0/Ghost.git
git submodule update --init
```
Open in visual studio and build.  
**Note that QT needs to be deployed before running.**
```
windeployqt WindowsSimulator.exe
```

## esp32s3
Will launch soon(perhaps).