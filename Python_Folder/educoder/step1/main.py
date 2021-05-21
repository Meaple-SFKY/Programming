from student import PlayMazz

if __name__ == '__main__':
    data = {'mazz': {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'F': [
        'G', 'H'], 'D': [], 'E': [], 'G': [], 'H': []}, 'start': 'A', 'end': 'D'}
    PlayMazz(data['mazz'], data['start'], data['end'])
