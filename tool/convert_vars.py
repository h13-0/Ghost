import os
import re
import time
import logging

from pathlib import Path

def _get_item_name(ghost_path : str, file_path : str = "") -> str:
    item_name = os.path.basename(file_path)
    return item_name


def _get_ITEM_NAME(ghost_path : str, file_path : str = "") -> str:
    ITEM_NAME = os.path.basename(file_path).upper()
    return ITEM_NAME


def _get_path(ghost_path : str, file_path : str = "") -> str:
    path = os.path.dirname(file_path)
    path = os.path.relpath(path, ghost_path)
    path = path.replace("\\", "/")
    return path


def _safe_str(_str : str) -> str:
    if(len(_str)):
        for c in _str:
            if not re.match('[a-zA-Z0-9_]', c):
                _str = _str.replace(c, "_")

        start_char = _str[0]
        if not re.match('[a-zA-Z_]', start_char):
            _str = "_" + _str

    return _str


def _get_safe_item_name(ghost_path : str, file_path : str = "") -> str:
    return _safe_str(_get_item_name(ghost_path, file_path))


def _get_SAFE_ITEM_NAME(ghost_path : str, file_path : str = "") -> str:
    return _safe_str(_get_item_name(ghost_path, file_path)).upper()


def _get_date(ghost_path : str, file_path : str = "") -> str:
    return time.strftime("%Y/%m/%d", time.localtime())


def _get_time(ghost_path : str, file_path : str = "") -> str:
    return time.strftime("%H:%M:%S", time.localtime()) 


def convert_vars(
    logger : logging.Logger, 
    ghost_path : str, file_path : str, 
    output : bool = False
    ) -> None:
    var_dict = {
        r"${item_name}" : _get_item_name,
        r"${file_name}" : _get_item_name,
        r"${ITEM_NAME}" : _get_ITEM_NAME,
        r"${FILE_NAME}" : _get_ITEM_NAME,
        r"${path}"      : _get_path,
        r"${safe_item_name}" : _get_safe_item_name,
        r"${SAFE_ITEM_NAME}" : _get_SAFE_ITEM_NAME,
        r"${date}" : _get_date,
        r"${time}" : _get_time,
    }

    file_content = ""
    with open(file_path, "r") as f:
        file_content = f.read()
        for key in var_dict.keys():
            file_content = \
                file_content.replace(key, var_dict[key](ghost_path, file_path))
    
    if(output):
        with open(file_path, "w") as f:
            f.write(file_content)
    else:
        logger.info(file_content)


def convert_vars_in_folder(
    logger : logging.Logger, 
    ghost_path : str, folder_path : str, 
    output : bool = False
    ) -> None:

    for parent, dirnames, filenames in os.walk(folder_path):
        for filename in filenames:
            if(
                filename.endswith(".h")
                or filename.endswith(".c")
                or filename.endswith(".hpp")
                or filename.endswith(".cpp")
            ):
                file_path = os.path.join(parent, filename)
                convert_vars(logger, ghost_path, file_path, output)


def main():
    # Init logger.
    logger = logging.getLogger("Ghost astyle tool")
    logger.setLevel(logging.INFO)
    ch = logging.StreamHandler()
    ch.setLevel(logging.INFO)
    logger.addHandler(ch)

    # Get template file path.
    tool_path = os.path.dirname(os.path.abspath(__file__))
    ghost_path = os.path.realpath(os.path.join(tool_path, "../"))

    # Run.
    convert_vars_in_folder(
        logger, ghost_path, os.path.join(ghost_path, "src/app/"), True)
    convert_vars_in_folder(
        logger, ghost_path, os.path.join(ghost_path, "src/core/"), True)
    convert_vars_in_folder(
        logger, ghost_path, os.path.join(ghost_path, "src/drivers/"), True)
    convert_vars_in_folder(
        logger, ghost_path, os.path.join(ghost_path, "src/platforms/"), True)

    convert_vars(
        logger, ghost_path, os.path.join(ghost_path, "src/ghost.h"), True)

    convert_vars(
        logger, ghost_path, os.path.join(ghost_path, "src/ghost.c"), True)

if __name__ == "__main__":
    main()

