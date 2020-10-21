
'''
    3 inputs:-
    -> FileExtension: 0 for CPP, 1 for Python, 2 for Java
    
    -> ProblemNumber(the prefix for the filename):
    for e.g 19 for DC of 19th Oct
    
    -> Problem Title/Problem Slug
    
    Sample Usage:
        1
        19
        Minimum Domino Rotations For Equal Row
        (or minimum-domino-rotations-for-equal-row)

    Sample Output:
        19_minimum_domino_rotations_for_equal_row.py

'''

def get_extension(extension):
    FILE_EXTENSIONS = {
        0: '.cpp',
        1: '.py',
        2: '.java'
    }
    return FILE_EXTENSIONS[extension]

def get_filename():
    print('\n FILE EXTENSIONS: 0 for CPP, 1 for Python, 2 for Java\n')
    extension = int(input('File Extension: '))
    problem_number = int(input('\nProblem Number: '))
    problem_slug = input('\nProblem Title/Slug: ').strip().lower().replace('-','_').replace(' ','_')
    filename = f'{problem_number}_{problem_slug}{get_extension(extension)}'
    print(filename)

if __name__ == "__main__":
    get_filename()
