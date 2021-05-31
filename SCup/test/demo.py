# testModel/test.py 这里是运行入口
import sys
import os
sys.path.append(os.path.abspath(".."))


from test1.student import get_name
from test1.newStu import get_student_name

if __name__ == "__main__":
    print(sys.path)
    print(get_name())
    print(get_student_name())
