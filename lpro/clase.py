from logica import *


def clase(p: bool, q: bool, r: bool):
    left = p or (not q)
    right = not r
    return unidir(left, right)


if __name__ == "__main__":
    genTabla(clase, "(P or not Q) arrow not R")
