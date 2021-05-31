# model1/new_student.py
from .student import get_name

# 注意这里的导入包的方式，会导致后面的异常


def get_student_name():
    return get_name()
