
# Peripheral configs.
## SPI
## I2C
## UART
## 

# Driver configs.
## Select ScreenDriver.
set(ScreenDriver "QT_GraphicsView")

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


