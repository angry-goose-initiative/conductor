import os

ABSOLUTE_SCRIPT_DIR = os.path.dirname(__file__) + "/"

RELATIVE_CODE_DIR = "../code/"

CODE = [
    "main.cc"
]

for file in CODE:
    print(ABSOLUTE_SCRIPT_DIR + RELATIVE_CODE_DIR + file)
    print(ABSOLUTE_SCRIPT_DIR + file)
    os.symlink(src=ABSOLUTE_SCRIPT_DIR + RELATIVE_CODE_DIR + file, dst=ABSOLUTE_SCRIPT_DIR + file)
