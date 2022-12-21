import os

import pycparser as pyc


class AppAPI_Generator:
    def __init__(self, tool_path : str):
        self.__gcc_path__ = os.path.join(tool_path, "Tools/MinGW/bin/gcc.exe")
        self.__path__ = os.path.join(tool_path, "AppAPIGenerator")
        self.__include_path__ = os.path.join(self.__path__ , "utils/fake_libc_include")
        
        pass

    def generate(self):
        test_file_path = os.path.join(self.__path__ , "test.c")
        ast = pyc.parse_file(test_file_path, use_cpp = True, cpp_path = 'gcc', cpp_args=["-nostdinc", '-E', "-I" + self.__include_path__])
        
        for ext in ast.ext:
            if(type(ext) == pyc.c_ast.FuncDef):
                print("bingo")

        #print(ast.ext[0].decl.type.type.names)
        #print('%s at %s' % (ast.decl.name, ast.decl.coord))
        pass

    def setup():
        # MinGW:
        ## w64devkit:
        ## https://github.com/skeeto/w64devkit/releases
        ## x86: https://github.com/skeeto/w64devkit/releases/download/v1.17.0/w64devkit-i686-1.17.0.zip
        ## x64: https://github.com/skeeto/w64devkit/releases/download/v1.17.0/w64devkit-1.17.0.zip

        pass

    

def main():
    # Get path of DeploymentTool.
    dirname = os.path.dirname(os.path.abspath(__file__))
    tool_path = os.path.realpath(os.path.join(dirname, ".."))

    # Generator
    generator = AppAPI_Generator(tool_path)
    generator.generate()



if __name__ == "__main__":
    main()

