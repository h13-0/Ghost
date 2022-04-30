# Ghost
![](Images/Logo.jpg)

An amazing watch.

# Functions and tasks
- [ ] Basic software framework.
  - [X] Support lvgl.
  - [ ] Support clock.
  - [ ] Support file system.
  - [ ] Power manager framework.
  - [ ] lua interpreter.
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