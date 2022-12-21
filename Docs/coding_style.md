---
last update: 2022/12/22 02:31
---

# Coding style
This rule will be executed in release 1.0 and later.

## 1 Template file
C source file:

C header file:

CMakeLists.txt:

If your IDE cannot automatically replace variables in the template, run DeploymentTool.  

## 2 C coding style
### 2.1 Naming conventions  
- Keywords separated by `_` ( `unix_like` ).  
- Try not to use global variables or extern variables in header files, you can use getters and setters instead.  
- C functions:  
  - Public functions should start with `ghost` , and private start with `_ghost`.  
  - Function naming rules:  
    - `ghost_${module}_${action}` or `ghost_${module}_${action}_${other_describe}`  
  - The same comment should be added before function declaration and definition.

- C file name:
  - File naming rules:  
    - `ghost_${module}` or `ghost_${module}_${submodule}.h`  
  - Folder naming rule:
    - `${module}`  
- C struct:

- C enum:
  - 
  - All enumerators should use uppercase `UNIX_LIKE` .  

- C macro:
  - All macro should use uppercase `UNIX_LIKE` .  



<details>
<summary>The reason for these conventions</summary>

Use `unix_like` instead of `Camel` :  
> Because we need to use the auto deployment script to bind the C function API to python and lua. Therefore, we need a better keyword segmentation method to bind python modules and other language.

</details>

## 3 Python coding style
### 3.1 Naming conventions  
- Class naming should follow the `Camel` rule.
- Function naming should follow the `unix_like` rule.
- Class member naming rules:
  - All member use `unix_like` , and private member should start with `__` .
  - 


