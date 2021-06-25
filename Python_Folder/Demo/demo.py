# from pyray.shapes.plane import *
#
#
# for i in range(20):
#     best_plane_direction(im_ind=i)


from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from matplotlib import pyplot as plt
import scipy.constants as C
import math
plt.xlabel('x')
plt.ylabel('f(E)')
plt.title("Potential_well")
E = np.arange(0, 4, 0.01)
pi = np.pi
h = C.h
hk = h/(2 * pi)
k = (np.sqrt(2 * 9.1 * (10 ** -31))) / hk
ev = 1.6021766208 * (10 ** -19)
U0 = 5 * ev
e = E * ev
alpha = k * np.sqrt(e)
beta = k * np.sqrt(U0 - e)
a = 10**-9
f = 2*beta*np.cos(alpha*a)+((beta*beta-alpha*alpha)*np.sin(alpha*a)/alpha)
plt.plot(E, f)
plt.show()
