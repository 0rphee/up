//
//  DetallePeliculaView.swift
//  examen3
//
//  Created by roger on 11/04/25.
//

import SwiftUI

struct DetallePeliculaView: View {
    var pelicula: Pelicula
    var onEditar: (Pelicula) -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: 12) {
            Text(pelicula.titulo).font(.title)
            Text("Director: \(pelicula.director)")
            Text("Año: \(pelicula.anio)")
            Text("Reseña: \(pelicula.resena)")
            Text("Calificación: " + String(pelicula.calificacion) + "/5")
            Text(pelicula.vista ? "VISTA" : "NO VISTA")
                .foregroundColor(pelicula.vista ? .green : .red)
                .fontWeight(.bold)

            Spacer()
        }
        .padding()
        .navigationTitle("Detalle")
        .toolbar {
            Button("Editar") {
                onEditar(pelicula)
            }
        }
    }
}

#Preview {
    DetallePeliculaView(pelicula: Pelicula.interestellar, onEditar: { p in })
}
