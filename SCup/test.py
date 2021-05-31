import sys
import os
sys.path.append(os.path.abspath("./test1"))

from test1.student import get_name
from test1.newStu import get_student_name
# from test2 import animal
# from test2 import newAni


if __name__ == "__main__":
    print(sys.path)
    print(get_name())
    print(get_student_name())
