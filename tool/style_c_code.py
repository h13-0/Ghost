
import os
import logging


def _style_src(ghost_path : str, relpath : str, config_file : str) -> str:
    return os.popen(
        "clang-format --style=" 
        + os.path.realpath(
            os.path.join(ghost_path, "tool/configs/" + config_file)
        )
        + os.path.realpath(os.path.join(ghost_path, relpath))
    ).read()


def style_c_code(
    logger : logging.Logger, ghost_path : str, config_file : str
    ) -> None:

    logger.info("Formatting c code...")

    logger.info(_style_src(ghost_path, "src/app/*.c,*.h", config_file))
    logger.info(_style_src(ghost_path, "src/core/*.c,*.h", config_file))
    logger.info(_style_src(ghost_path, "src/platforms/*.c,*.h", config_file))
    logger.info(_style_src(ghost_path, "src/template/*.c,*.h", config_file))


def main():
    # Init logger.
    logger = logging.getLogger("Ghost astyle tool")
    logger.setLevel(logging.INFO)
    ch = logging.StreamHandler()
    ch.setLevel(logging.INFO)
    logger.addHandler(ch)

    # Get ghost path.
    tool_path = os.path.dirname(os.path.abspath(__file__))
    ghost_path = os.path.realpath(os.path.join(tool_path, "../"))

    # Run.
    style_c_code(logger, ghost_path, "./code-format.cfg")


if __name__ == "__main__":
    main()

