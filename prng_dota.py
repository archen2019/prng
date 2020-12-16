from decimal import *
import math

# set precision for decimals
getcontext().prec = 50

# converts p to c
def ptoc(p):
    c_lb = Decimal(0)
    c_ub = p
    p_est = Decimal(1)
    while True:
        c_mid = (c_lb + c_ub) / Decimal(2)
        new_p_est = ctop(c_mid)
        if abs(p_est - new_p_est) <= Decimal(0):
            break

        if new_p_est <= p:
            c_lb = c_mid
        else:
            c_ub = c_mid

        p_est = new_p_est

    return c_mid

# converts c to p
def ctop(c):
    proc_on_k = Decimal(0)
    proc_by_k = Decimal(0)
    p_inv = Decimal(0)

    max_fails = math.ceil(Decimal(1) / c)
    for k in range(1, math.ceil(Decimal(1) / c) + 1):
        proc_on_k = min(Decimal(1), k * c) * (Decimal(1) - proc_by_k)
        proc_by_k += proc_on_k
        p_inv += k * proc_on_k

    return Decimal(1) / p_inv
