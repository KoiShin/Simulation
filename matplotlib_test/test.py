import numpy as np
import matplotlib.pyplot as plt

x = np.arange(0, 10, 0.1)
y = np.exp(x)
plt.plot(x, y)
plt.title("$ y = e^x $")
plt.show()
