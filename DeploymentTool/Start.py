import os
import logging
from safe_lvgl_converter import SafeLVGL_Generator


def main():
    # Get path of DeploymentTool.
    tool_path = os.path.realpath(os.path.dirname(os.path.abspath(__file__)))
    lvgl_path = os.path.realpath(os.path.join(tool_path, "../Ghost/Thirdparty/lvgl"))
    safe_lvgl_path = os.path.realpath(os.path.join(tool_path, "../Ghost/App/Components/safe_lvgl"))
    template_header = os.path.realpath(os.path.join(tool_path, "./Configs/header_template.h"))
    template_source = os.path.realpath(os.path.join(tool_path, "./Configs/source_template.c"))
    template_func_decl = os.path.realpath(os.path.join(tool_path, "./Configs/func_decl_template.h"))
    template_func_def  = os.path.realpath(os.path.join(tool_path, "./Configs/func_def_template.c"))

    # Parse
    generator = SafeLVGL_Generator(
        lvgl_path = lvgl_path, safe_lvgl_path = safe_lvgl_path,
        compiler_path = "gcc",
        template_header = template_header, template_source = template_source,
        template_func_decl = template_func_decl, template_func_def = template_func_def
    )

    # Setup logger.
    generator.logger.setLevel(logging.INFO)
    ch = logging.StreamHandler()
    ch.setLevel(logging.INFO)
    generator.logger.addHandler(ch)
    
    # Generate safe_lvgl.
    generator.parse([ "-DLV_MEM_CUSTOM=1" ])
    generator.gen_safe_lvgl()

if __name__ == "__main__":
    main()
