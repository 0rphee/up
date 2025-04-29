//
//  FormularioPeliculaView.swift
//  examen3
//
//  Created by roger on 11/04/25.
//

import SwiftUI

struct FormularioPeliculaView: View {
    @Environment(\.dismiss) var dismiss
    @State private var titulo = ""
    @State private var director = ""
    @State private var anio = ""
    @State private var resena = ""
    @State private var calificacion = 3
    @State private var vista = false

    var pelicula: Pelicula?
    var onGuardar: (Pelicula) -> Void

    var body: some View {
        NavigationView {
            Form {
                Section {
                    TextField("Título", text: $titulo)
                    TextField("Director", text: $director)
                    TextField("Año", text: $anio)
                }
                Section(header: Text("Reseña")) {
                    TextEditor(text: $resena).frame(height: 100)
                }
                Section {
                    Stepper(
                        "Calificación: \(calificacion)",
                        value: $calificacion,
                        in: 1...5
                    )
                    Toggle("Vista", isOn: $vista)
                }
            }
            .navigationTitle(
                pelicula == nil ? "Nueva Película" : "Editar Película"
            )
            .toolbar {
                ToolbarItem(placement: .confirmationAction) {
                    Button("Guardar") {
                        guard !titulo.isEmpty, !director.isEmpty, !anio.isEmpty
                        else {  return }
                        let id = (pelicula?.id ?? UUID())
                        let nueva = Pelicula(
                            id: id,
                            titulo: titulo,
                            director: director,
                            anio: Int(anio)!,
                            resena: resena,
                            calificacion: calificacion,
                            vista: vista
                        )
                        onGuardar(nueva)
                        dismiss()
                    }
                }
                ToolbarItem(placement: .cancellationAction) {
                    Button("Cancelar") { dismiss() }
                }
            }
        }
        .onAppear {
            if let p = pelicula {
                titulo = p.titulo
                director = p.director
                anio = String(p.anio)
                resena = p.resena
                calificacion = p.calificacion
                vista = p.vista
            }
        }
    }
}

#Preview {
    FormularioPeliculaView(onGuardar: { a in
    })
}
