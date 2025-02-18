//
//  Sobre.swift
//  linktree
//
//  Created by roger on 14/02/25.
//

import SwiftUI

struct Sobre: View {
    var body: some View {
        VStack(spacing: 20) {
            Text("Sobre mí").bold().font(.title)
            Text(sobreMi).multilineTextAlignment(.leading)
            Text("Hobbies").bold().font(.title2)
            Text(hobbies).multilineTextAlignment(.leading)
        }
        .padding()
        .navigationTitle("Sobre mí")
    }
}

#Preview {
    Sobre()
}

let sobreMi = """
            Soy un estudiante de Filosofía y de Ing. en Inteligencia de Datos y Ciberseguridad. Me interesa la lógica y la programación funcional, especialmente lenguajes como Haskell e Idris2.
    """

let hobbies = """
        En mi tiempo libre me gusta leer, jugar tenis e ir al gimnasio. Ya no suelo jugar videojuegos, pero entre mis juegos favoritos están Overwatch, Halo Reach y Civ VI.

        También me gusta mucho trabajar en proyectos de código propios para resolver problemas que tenga o simplemente investigar algún tema que me interese. Me agradan mucho los lenguajes funcionales, y siempre que puedo hago mis proyectos en alguno de estos, como Haskell, Elm o Rust. Sin embargo, a futuro también me gustaría aprender y trabajar con C. 
    """
