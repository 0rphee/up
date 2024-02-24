
def unidir(p: bool, q: bool):
    if p == True and q == False:
        return False
    else:
        return True

def bidir(p: bool, q: bool):
    if p == q:
        return True
    else:
        return False

def genTabla(func, nomFunc: str, typst=True):
    def s(v: bool):
        if v == True: return "V"
        else: return "F"
    tabla = f"""
#table(
  columns: (auto, auto, auto, auto),
  inset: 10pt,
  align: horizon,
  [*P*], [*Q*], [*R*], [*${nomFunc}$*],
"""

    tVals = (True, False)

    if not typst:
        print("nomFunc\nP\tQ\tR\tRES")

    comb = [(p, q, r) for p in tVals for q in tVals for r in tVals]
    for (p, q, r) in comb:
        res = func(p,q,r)
        if not typst:
            print(f"{p}\t{q}\t{r}\t{res}")
        tabla += f"  ${s(p)}$, ${s(q)}$, ${s(r)}$, align(center)[${s(res)}$],\n"

    tabla += ")\n"

    if not typst:
        print()

    print(tabla)
