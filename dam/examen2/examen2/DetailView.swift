//
//  DetailView.swift
//  exp2
//
//  Created by roger on 11/04/25.
//

import SwiftUI

struct DetailView: View {
    var peliculaAEditar: Pelicula
    var onGuardar: (Pelicula) -> Void

    @Environment(\.dismiss) var dismiss

    @State private var titulo: String = ""
    @State private var director: String = ""
    @State private var anioStr: String = ""
    @State private var resena: String = ""
    @State private var calificacion: Int = 3
    @State private var vista: Bool = false

    @State private var mostrarAlerta = false
    @State private var mensajeAlerta = ""

    var body: some View {
        NavigationView {
            Form {
                Section("Información Básica") {
                    TextField("Título", text: $titulo)
                    TextField("Director", text: $director)
                    TextField("Año de Estreno", text: $anioStr)
                        .keyboardType(.numberPad)
                }

                Section("Detalles") {
                    TextEditor(text: $resena)
                        .frame(height: 100)
                    ZStack(alignment: .topLeading) {
                        if resena.isEmpty {
                            Text("Reseña...")
                                .foregroundColor(Color(UIColor.placeholderText))
                                .padding(.top, 8)
                                .padding(.leading, 5)
                                .allowsHitTesting(false)
                        }
                        TextEditor(text: $resena)
                            .frame(height: 100)
                    }

                    Stepper(
                        "Calificación: \(calificacion)",
                        value: $calificacion,
                        in: 1...5
                    )

                    Toggle("¿Vista?", isOn: $vista)
                }
            }
            .navigationTitle("Editar Película")
            .navigationBarTitleDisplayMode(.inline)
            .toolbar {
                ToolbarItem(placement: .navigationBarLeading) {
                    Button("Cancelar") {
                        dismiss()
                    }
                }
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button("Guardar") {
                        guardar()
                    }
                }
            }
        }
        .alert(mensajeAlerta, isPresented: $mostrarAlerta) {
            Button("Ok", role: .cancel) {}
        }
    }
    func guardar() {
        guard self.titulo.isEmpty else {
            self.mensajeAlerta = "El título no puede estar vacío."
            self.mostrarAlerta = true
            return
        }
        guard self.director.isEmpty else {
            self.mensajeAlerta = "El director no puede estar vacío."
            self.mostrarAlerta = true
            return
        }
        guard let anio = Int(self.anioStr), anio > 1800 && anio < 2100
        else {
            self.mensajeAlerta = "Ingresa un año válido (ej. 2023)."
            self.mostrarAlerta = true
            return
        }
        onGuardar(peliculaAEditar)

        dismiss()
    }

}

#Preview {
    VStack {

        DetailView(peliculaAEditar: Pelicula.interestellar) {
            peliculaGuardada in
            print("Guardando película: \(peliculaGuardada.titulo)")
        }

        DetailView(peliculaAEditar: Pelicula.dune) { peliculaGuardada in
            print("Guardando película editada: \(peliculaGuardada.titulo)")
        }

    }
}
