#! /usr/bin/python3
import os
import re
from pathlib import Path

path = "./Ghost/"

whitelist_paths = ["App", "Drivers", "Platforms"]

blacklist_file_keys = [
    "safe", "Safe", "conf", "CMakeC", "foo", "TargetDirectories.txt", 
    ]

def main(source_path : str):
    """
    """

    line_count = 0
    # Traversal header file.
    for parent, dirnames, filenames in os.walk(source_path):
        parent_path = Path(parent)
        is_white_path = False
        while(os.path.relpath(parent_path) != os.path.relpath(source_path)):
            for path in whitelist_paths:
                if(os.path.relpath(parent_path) == os.path.relpath(os.path.join(source_path, path))):
                    is_white_path = True
                    break
            parent_path = parent_path.parent
        
        if(is_white_path):
            for filename in filenames:
                is_legal_file = True
                for blacklist_file_key in blacklist_file_keys:
                    if(filename.find(blacklist_file_key) != -1):
                        is_legal_file = False
                        break

                if(is_legal_file):
                    ext = os.path.splitext(filename)[1][1:]
                    if ext =="h" or ext == "c" or ext == "cpp" or ext == "txt" or ext == "py":
                        lines = 0
                        source_file = open(os.path.join(parent, filename), 'r', encoding="utf-8")
                        while True:
                            try:
                                code = source_file.readline()
                                if(code):
                                    lines += 1
                                else:
                                    line_count += lines
                                    print(filename + " " + str(lines) + " lines.")
                                    break
                            except Exception as e:
                                print(filename + " " + str(e))
                                break

                        source_file.close()

    print("Total " + str(line_count) + " lines.")


if(__name__ == "__main__"):
    main(path)