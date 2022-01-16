
# Peripheral configs.
## SPI
## I2C
## UART
## 

# Driver configs.
## Select ScreenDriver.
set(ScreenDriver "QT_GraphicsView")
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
QT5_WRAP_UI()


# Sensor configs.
## Select GyroscopeDriver.
set(IsGyroscopeEnable ON CACHE BOOL "" FORCE)
if(${IsGyroscopeEnable})
	set(GyroscopeDriver "Random")
endif()

## Select Compass.

# Application configs.
## Screen type.
### Round or Rectangle.
set(ScreenType "Rectangle")


