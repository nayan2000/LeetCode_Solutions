'''
    To run:
    (If in utils folder)
    python filename_generator.py
    (If in the project directory)
    python utils/filename_generator.py

    3 inputs:-
    -> FileExtension: 0 for CPP, 1 for Python, 2 for Java
    
    -> ProblemNumber(the prefix for the filename):
    for e.g 19 for DC of 19th Oct
    
    -> Problem Title/Problem Slug:
    Accepts 3 formats:
    1) 1621. Number of Sets of K Non-Overlapping Line Segments
    2) Number of Sets of K Non-Overlapping Line Segments
    3) number-of-sets-of-k-non-overlapping-line-segments
    Note: 2) and 3) use the Problem Number to prefix in filename, while
    1) doesnot consider the ProblemNumber argument.
    
    Sample Usage:
        1
        19
        Minimum Domino Rotations For Equal Row
        (or minimum-domino-rotations-for-equal-row)

    Sample Output(gets copied to clipboard):
        19_minimum_domino_rotations_for_equal_row.py

'''

import config

from background_colors import bcolors
import re

try:
    import pyperclip
    to_copy = True
except ModuleNotFoundError:
    to_copy = False
    print(f"{bcolors.BOLD}{bcolors.FAIL}The Module Pyperclip not found. You need to manually copy the filename.{bcolors.ENDC}")
    print(f"{bcolors.BOLD}{bcolors.FAIL}Is the Virtual Environment activated? If yes, Run pip3 install pyperclip to fix this.{bcolors.ENDC}")

def copy_to_clipboard(text):
    pyperclip.copy(text)

def get_extension(extension):
    FILE_EXTENSIONS = {
        0: '.cpp',
        1: '.py',
        2: '.java'
    }
    return FILE_EXTENSIONS.get(extension,FILE_EXTENSIONS[config.DEFAULT_EXTENSION])

def get_filename():
    print('\n FILE EXTENSIONS: 0 for CPP, 1 for Python, 2 for Java\n')

    try:
        extension = int(input('File Extension: '))
    except:
        extension = config.DEFAULT_EXTENSION

    try:
        problem_number = int(input('\nProblem Number: '))
    except:
        problem_number = ''

    problem_slug = input('\nProblem Title/Slug: ').strip().lower().replace('-','_').replace(' ','_')
    problem_no_format = re.findall('^\d*[.]',problem_slug)
    problem_slug = problem_slug.replace('.','')

    if problem_no_format or not problem_number:
        # doesnt require explicity int() typecast as it will be used in string only
        filename = f'{problem_slug}{get_extension(extension)}'

    else:
        filename = f'{problem_number}_{problem_slug}{get_extension(extension)}'

    if to_copy:
        print(f'\n{bcolors.BOLD}{bcolors.OKCYAN}FileName: {filename} has been copied to clipboard.{bcolors.ENDC}')
        copy_to_clipboard(filename)

    else:
        print(f'\n{bcolors.BOLD}{bcolors.OKCYAN}FileName: {filename}{bcolors.ENDC}')

if __name__ == "__main__":
    get_filename()
