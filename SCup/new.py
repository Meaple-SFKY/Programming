import argparse

parser = argparse.ArgumentParser(description='test')
parser.add_argument('--gpu_id', default=1, type=int)
parser.add_argument('--size', default=32, type=int)
parser.add_argument('--root', default='/users/xxx', type=str)
args = parser.parse_args()
print(args)
argsDict = args.__dict__
with open('setting.txt', 'w') as f:
    f.writelines('------------------ start ------------------' + '\n')
    for eachArg, value in argsDict.items():
        f.writelines(eachArg + ' : ' + str(value) + '\n')
    f.writelines('------------------- end -------------------')

