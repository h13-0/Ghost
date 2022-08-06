# Ghost Native主题开发文档

## Ghost主题管理框架
请开发者在主题开发前阅读并理解[主题管理器框架](https://github.com/h13-0/Ghost/tree/master/Ghost/App/NativeApplications/ThemeManager/ReadmeCN.md#Ghost主题管理器框架)后再进行主题开发。  

## 开发守则
### 允许修改的范围
`GhostThemeManager.c`

如需修改其他文件，请额外提交PR.

### 允许调用的函数
`GhostTheme.h`中**声明**的所有的函数(不包括该文件引用的其他头文件中声明的函数)。  
C标准库`math.h`中所有函数。  

### 资源与控件管理

### 主题初始化函数与析构函数


### 页面初始化函数与析构函数


### 设置页面刷新频率
页面刷新频率应在各个页面的构造函数中被设置。
```C

```

### 页面刷新回调函数



### 汇总句柄并注册至主题管理器
打开`GhostThemeManager.c`文件，找到`ghostBuiltInThemeRegister`的函数定义。  


### 添加主题截图到文档

## Api列表
