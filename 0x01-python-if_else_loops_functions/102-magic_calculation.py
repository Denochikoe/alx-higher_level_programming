import dis

def calculate(a, b, c):
    if a < b:
        return c
    elif c < b:
        return a + b
    else:
        return a * b - c

dis.dis(calculate)
