#import "@preview/ilm:1.4.0": *
#import "@preview/finite:0.4.1": automaton
#import "@preview/finite:0.4.1" as finite

#set text(lang: "es")

#show link: it => underline(text(fill: blue, it));

#show: ilm.with(
  title: [Teoría de Lenguajes y Programación],
  author: "",
  date: datetime(year: 2025, month: 01, day: 30),
  date-format: "[day padding:zero]-[month repr:numerical]-[year repr:full]",
  // table-of-contents: outline(title: "custom title"),
  abstract: [Sesion 2],
  // bibliography: bibliography("refs.bib"),
  // figure-index: (enabled: true, title: "figindex"),
  // table-index: (enabled: true, title: "tabindex"),
  // listing-index: (enabled: true, title: "listindex"),
  paper-size: "us-letter",
  chapter-pagebreak: false,
  external-link-circle: false,
  // appendix: (
  //   enabled: true,
  //   title: "Appendix", // optional
  //   heading-numbering-format: "A.1.1.", // optional
  //   body: [
  //     = First Appendix
  //     = Second Appendix
  //   ],
  // ),
)

= Reglas de producción (Expresiones Regulares)

#block(stroke: 1pt + black, inset: 1em)[
  Regla para convertir producciones a ER.
  - C $->$ cC | c
  - C $->$ {c}c
]
- Gramática original:
  + S $->$ aA
  + A $->$ bA
  + A $->$ cB
  + B $->$ bB
  + B $->$ b
- Simplificada:
  + S $->$ aA
  + A $->$ bA | cB
  + B $->$ bB | b
- ER 1:
  + S $->$ aA
  + A $->$ bA | c{b}b

- ER 2:
  + S $->$ a({b}b | c{b}b)

- ER 3:
  + S $->$ a{b}c{b}b

= Fórmulas de Thompson

Autómata finito no determinista con estados vacíos: cambia de estado sin tener entradas.

1. $a in V_T$:
  #scale(
    70%,
    automaton((
      I: (F: "a"),
      F: (),
    )),
  )
2. $E_R space {E_R}$: $I ->epsilon space E_R space ->epsilon F$
  #scale(
    70%,
    automaton(
      (
        I: (ER1: sym.epsilon, F: sym.epsilon),
        ER1: (F: sym.epsilon),
        F: (I: sym.epsilon),
      ),
      labels: (
        ER1: $E_R^1$,
        ER2: $E_R^2$,
      ),
      layout: finite
        .layout
        .custom
        .with(
          positions: (..) => (
            I: (0, 0),
            ER1: (2, 0),
            ER2: (2, 2),
            F: (4, 0),
          ),
        ),
      style: (
        I-F: (curve: -1),
        F-I: (curve: -1.75),
      ),
    ),
  )
3. $E_R^1,$ $E_R^2$: $E_R^1 dot E_R^2$
  #scale(
    70%,
    automaton(
      (
        I: (ER1: sym.epsilon),
        ER1: (ER2: sym.epsilon),
        ER2: (F: sym.epsilon),
        F: (),
      ),
      labels: (
        ER1: $E_R^1$,
        ER2: $E_R^2$,
      ),
    ),
  )
4. $E_R^1$, $E_R^2$: $E_R^1 | E_R^2$:
  #scale(
    70%,
    automaton(
      (
        I: (ER1: sym.epsilon, ER2: sym.epsilon),
        ER1: (F: sym.epsilon),
        ER2: (F: sym.epsilon),
        F: (),
      ),
      labels: (
        ER1: $E_R^1$,
        ER2: $E_R^2$,
      ),
      layout: finite
        .layout
        .custom
        .with(
          positions: (..) => (
            I: (0, 0),
            ER1: (2, 0),
            ER2: (2, 2),
            F: (4, 0),
          ),
        ),
    ),
  )
$"AFN"_epsilon$:
- $K != emptyset$: estados
- $S in K$: estado inicial
- $V_T != emptyset$: alfabeto
- $Z subset.eq K$: estados finales


$"Cerradura"_epsilon ({1,2,3})$: conjunto de todos los estados que pueden ser alcanzados desde los estados {1,2,3} mediante transiciones vacías.
