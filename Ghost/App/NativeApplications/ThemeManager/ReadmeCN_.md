# Ghost主题管理器
本文档为Ghost主题管理器开发文档，[主题开发文档](../../../../Docs/Developer/Theme/ReadmeCN.md )请自行点击跳转。
  
##  Ghost主题管理器框架
  

```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\h13\AppData\Local\Temp\mume-mermaid2022720-2628-cx1m8w.s6aqn.mmd --output C:\Users\h13\Desktop\GhostDevelop\Ghost\assets\73cd6d9b4e1ab51298d2c6c2cda240530.png
(node:2544) UnhandledPromiseRejectionWarning: Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\19588\node_modules\@mermaid-js\mermaid-cli\node_modules\ws'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\19588\node_modules\@mermaid-js\mermaid-cli\node_modules\puppeteer\lib\cjs\puppeteer\node\NodeWebSocketTransport.js:34:30)
    at Module._compile (internal/modules/cjs/loader.js:1139:30)
(node:2544) UnhandledPromiseRejectionWarning: Unhandled promise rejection. This error originated either by throwing inside of an async function without a catch block, or by rejecting a promise which was not handled with .catch(). To terminate the node process on unhandled promise rejection, use the CLI flag `--unhandled-rejections=strict` (see https://nodejs.org/api/cli.html#cli_unhandled_rejections_mode). (rejection id: 1)
(node:2544) [DEP0018] DeprecationWarning: Unhandled promise rejections are deprecated. In the future, promise rejections that are not handled will terminate the Node.js process with a non-zero exit code.
internal/modules/cjs/loader.js:625
  throw e;
  ^

Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\19588\node_modules\@mermaid-js\mermaid-cli\node_modules\commander'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\19588\node_modules\@mermaid-js\mermaid-cli\index.bundle.js:4:41)
    at Module._compile (internal/modules/cjs/loader.js:1139:30) {
  code: 'MODULE_NOT_FOUND'
}

```  

  
##  Ghost主题管理器内部实现
  
###  主题类型
  

```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\h13\AppData\Local\Temp\mume-mermaid2022720-2628-1r7zt6j.9y5c.mmd --output C:\Users\h13\Desktop\GhostDevelop\Ghost\assets\73cd6d9b4e1ab51298d2c6c2cda240531.png
(node:24744) UnhandledPromiseRejectionWarning: Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\22296\node_modules\@mermaid-js\mermaid-cli\node_modules\ws'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\22296\node_modules\@mermaid-js\mermaid-cli\node_modules\puppeteer\lib\cjs\puppeteer\node\NodeWebSocketTransport.js:34:30)
    at Module._compile (internal/modules/cjs/loader.js:1139:30)
(node:24744) UnhandledPromiseRejectionWarning: Unhandled promise rejection. This error originated either by throwing inside of an async function without a catch block, or by rejecting a promise which was not handled with .catch(). To terminate the node process on unhandled promise rejection, use the CLI flag `--unhandled-rejections=strict` (see https://nodejs.org/api/cli.html#cli_unhandled_rejections_mode). (rejection id: 1)
(node:24744) [DEP0018] DeprecationWarning: Unhandled promise rejections are deprecated. In the future, promise rejections that are not handled will terminate the Node.js process with a non-zero exit code.
internal/modules/cjs/loader.js:625
  throw e;
  ^

Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\22296\node_modules\@mermaid-js\mermaid-cli\node_modules\commander'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\22296\node_modules\@mermaid-js\mermaid-cli\index.bundle.js:4:41)
    at Module._compile (internal/modules/cjs/loader.js:1139:30) {
  code: 'MODULE_NOT_FOUND'
}

```  

  
###  页面类型
  

```
Error: mermaid CLI is required to be installed.
Check https://github.com/mermaid-js/mermaid-cli for more information.

Error: Command failed: npx -p @mermaid-js/mermaid-cli mmdc --theme default --input C:\Users\h13\AppData\Local\Temp\mume-mermaid2022720-2628-gapvf7.4vqna.mmd --output C:\Users\h13\Desktop\GhostDevelop\Ghost\assets\73cd6d9b4e1ab51298d2c6c2cda240532.png
(node:10288) UnhandledPromiseRejectionWarning: Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\10104\node_modules\@mermaid-js\mermaid-cli\node_modules\ws'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\10104\node_modules\@mermaid-js\mermaid-cli\node_modules\puppeteer\lib\cjs\puppeteer\node\NodeWebSocketTransport.js:34:30)
    at Module._compile (internal/modules/cjs/loader.js:1139:30)
(node:10288) UnhandledPromiseRejectionWarning: Unhandled promise rejection. This error originated either by throwing inside of an async function without a catch block, or by rejecting a promise which was not handled with .catch(). To terminate the node process on unhandled promise rejection, use the CLI flag `--unhandled-rejections=strict` (see https://nodejs.org/api/cli.html#cli_unhandled_rejections_mode). (rejection id: 1)
(node:10288) [DEP0018] DeprecationWarning: Unhandled promise rejections are deprecated. In the future, promise rejections that are not handled will terminate the Node.js process with a non-zero exit code.
internal/modules/cjs/loader.js:625
  throw e;
  ^

Error: No valid exports main found for 'C:\Users\h13\AppData\Roaming\npm-cache\_npx\10104\node_modules\@mermaid-js\mermaid-cli\node_modules\commander'
    at resolveExportsTarget (internal/modules/cjs/loader.js:622:9)
    at applyExports (internal/modules/cjs/loader.js:499:14)
    at resolveExports (internal/modules/cjs/loader.js:548:12)
    at Function.Module._findPath (internal/modules/cjs/loader.js:654:22)
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:953:27)
    at Function.Module._load (internal/modules/cjs/loader.js:859:27)
    at Module.require (internal/modules/cjs/loader.js:1028:19)
    at require (internal/modules/cjs/helpers.js:72:18)
    at Object.<anonymous> (C:\Users\h13\AppData\Roaming\npm-cache\_npx\10104\node_modules\@mermaid-js\mermaid-cli\index.bundle.js:4:41)
    at Module._compile (internal/modules/cjs/loader.js:1139:30) {
  code: 'MODULE_NOT_FOUND'
}

```  

  
  