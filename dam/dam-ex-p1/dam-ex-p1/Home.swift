//
//  Home.swift
//  dam-ex-p1
//
//  Created by roger on 21/02/25.
//

import SwiftUI

struct Home: View {
    var user: String
    var body: some View {
        NavigationView {
            VStack(spacing: 20) {
                Text("Bienvenido, \(user)").font(.largeTitle).bold()

                Text(
                    "SwiftUI es un framework declarativo de Apple que permite construir interfaces de usuario de manera rápida y eficiente para iOS, macOS, watchOS y tvOS."
                ).multilineTextAlignment(.leading).padding(.horizontal, 30)
                Text(
                    "El lenguaje Swift es moderno, seguro y optimizado para el rendimiento, lo que lo convierte en una excelente opción para el desarrollo de aplicaciones móviles."
                ).multilineTextAlignment(.leading).padding(.horizontal, 10)

                Text(
                    "El modificador @State en SwiftUI permite gestionar cambios en una vista, asegurando que los datos actualizados se reflejen automáticamente en la interfaz."
                ).multilineTextAlignment(.leading).padding(.horizontal, 40)
            }
        }.navigationTitle("Home")
    }
}

#Preview {
    Home(user: "admin")
}
