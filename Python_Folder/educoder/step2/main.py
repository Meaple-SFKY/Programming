from student import PlayMazz

if __name__ == '__main__':
    data = {'mazz': {'A': ['B', 'E'], 'B': ['C', 'D'],
                     'C': [], 'D': [], 'E': []}, 'start': 'A', 'end': 'E'}
    PlayMazz(data['mazz'], data['start'], data['end'])
