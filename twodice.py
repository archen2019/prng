from decimal import *
import math

import numpy as np

mult = 5

buckets = np.full(36, 1/36)

while True:
    roll = np.random.choice(36, p=buckets)
    input('Press enter to roll again.')
