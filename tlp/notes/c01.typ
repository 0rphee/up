#import "@preview/ilm:1.4.0": *

#set text(lang: "es")

#show link: it => underline(text(fill: blue, it));

#show: ilm.with(
  title: [Teoría de Lenguajes y Programación],
  author: "",
  date: datetime(year: 2025, month: 01, day: 28),
  date-format: "[day padding:zero]-[month repr:numerical]-[year repr:full]",
  // table-of-contents: outline(title: "custom title"),
  abstract: [],
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

= Compilador

Código fuente $->$ An. lexicográfico $->$ An. sintáctico $->$ An. semántico $->$ Código destino

= Chomsky

- Para describir un leng. se debe formalizar su gramática.
- Gramática: conj. de reglas que definen como se escribe un lenguaje.
  - Componentes:
    - $V_t != emptyset$: conj. de símbolos terminales.
      - ej.: ${a, b, ..., z, A...Z, ...}$
    - $V_n != emptyset$: conj. de símbolos no terminales, conceptos abstractos que describen como producir oraciones en el lenguaje.
      - ej.: ${"oración", "artículo", ...}$
    - $S$: símbolo inicial, $S in V_n.$
      - ej. oración.
    - $phi.alt != emptyset$: conj. de reglas del lenguaje.
      - ej.:
        - oración $->$ sujeto predicado
        - sujeto $->$ sustantivo
        - sujeto $->$ ...
      - ej. $phi.alt$:
        - $S -> "ABa"$
        - $S -> a$
        - $A -> b$
        - $B -> "bB"$
- 4 tipos de gramáticas
  - G. Regular
    - Reglas
      1. $|alpha| <= |beta|$
      2. $alpha in V_n$
        1. $P = {a,b,c}$
        2. $P^2 = {"aa","ab","ac","bb","ba","bc","ca","cb","cc"}$
        3. $P^k = P P^(k-1)$
        4. $P^3 = P P^2 = {"aaa","aba","aca",...}$
        5. $α in (V_n)^+$
        6. $V^+ = V V^2 V^3 V^4 ...$
      3. $beta$ solo puede tener 2 formas:
        1. 1 terminal: $V_T$
        2. 1 terminal y 1 no terminal: $V_N V_T$
    - Una Gramática Regular (GR) $->$ Expresión Regular (ER) $->$ Autómata Finito No Determinista con transiciones vacías ($"AFN"_epsilon$) $->$ Autómata Finito Determinista (AFD).

- *Expresión Regular (ER)*
  - Asumiendo: concatenación, disyunción y repetición de 0 o más.
  1. $epsilon$ es una ER: $L(epsilon) -> epsilon$
  2. $a in V_T$ es una ER: $L(a) -> a$
  3. $e_1 -> L_1, e_2 -> L_2$
    1. $e_1 e_2$ $L_1 L_2$
    2. $e_1 | e_2$ $L_1 union L_2$
    3. ${e_1}$ $L_1^*$
