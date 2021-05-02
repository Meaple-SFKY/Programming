import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
sin = np.sin(X)
plt.plot(X, sin, "b-", lw=2.5, label="正弦", color='deepskyblue')
plt.show()
