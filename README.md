# Ghost
<div align = "center">
  <img src = "Images/Logo.jpg">
  <h1 align = "center">An amazing watch.</h1>
</div>

# Functions and tasks
- [ ] Basic software framework.
  - [X] Support lvgl.
  - [X] Ghost Package manager.
  - [X] Ghost Clock.
  - [X] Ghost Thread.
  - [X] Ghost File system.
  - [X] Ghost safe lvgl.
  - [ ] lua interpreter.
  - [ ] Ghost Power manager.
- [ ] Basic function realization.
  - [X] Basic clock function.
  - [ ] Launcher and theme.
  - [ ] Built in applications.
    - [ ] Calculator.
  - [ ] Built in games.
    - [ ] Flappy bird.
- [ ] Ghost installable application support.
  - [ ] Authority manager.
- [ ] PCB and BOM.
  - [ ] Migrate to esp-idf.
- [ ] Mechanical structure.

# Build
## Windows Simulator
```Powershell
git clone https://github.com/h13-0/Ghost.git
git submodule update --init
```
Open in visual studio and build.  
**Note that QT needs to be deployed before running.**
```Powershell
windeployqt WindowsSimulator.exe
```

## esp32s3
Will launch soon(perhaps).