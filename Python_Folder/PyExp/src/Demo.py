import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model
import csv

data = np.loadtxt(open("./PyExp/data/data_fir.csv", "r", encoding="utf-8"), delimiter=",", skiprows=1)
# data = np.loadtxt(open("./PyExp/data/data_sec.csv", "r", encoding="utf-8"), delimiter=",", skiprows=1)
data = np.split(data, 2, axis = 1)

# d_left = data[0]
# d_right = data[1]

y = (data[0] - data[1]) ** 2
x = np.arange(3, 22).reshape(-1, 1)
y = np.array(y).reshape(-1, 1)

lrmodel = linear_model.LinearRegression()
lrmodel.fit(x, y)
result = lrmodel.predict(x)
b = lrmodel.coef_
R = b / (4 * 539.3e-6)

n = y.size
e_2 = np.sum((y - result) ** 2) / (n - 2)
u_B1 = 0.001 / np.sqrt(3)
u_B2 = 0.04 / 6
u_y = np.sqrt(e_2 + u_B1 ** 2 + u_B2 ** 2)
u_b = u_y / np.sqrt(np.sum((x - np.mean(x)) ** 2))
u_R = u_b / (4 * 589.3e-6)
e_R = u_R / R
print("E_R = %f" %e_R)

plt.figure()
plt.scatter(x, y, label = "true value")
plt.plot(x, result, "r", label = "predict value")
plt.title("b = %f R = %.2fmm" %(b, R))
plt.xlabel("k")
plt.ylabel("D^2")
plt.legend()
plt.savefig("./PyExp/img/demo_fir.png")
# plt.savefig("./PyExp/img/demo_sec.png")
plt.show()
