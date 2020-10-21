# LeetCode Solutions in C++ and python3

<pre>pip install -r requirements.txt</pre> 
## For generating filename and copying it to clipboard
<pre>
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
</pre>