//
//  AgregarTarea.swift
//  todolist
//
//  Created by roger on 04/04/25.
//

import SwiftUI

struct AgregarTareaView: View {
    @Environment(\.dismiss) var dismiss
    @State private var notaTitulo = ""
    @State private var notaDescripcion = ""

    var onAgregar: (Tarea) -> Void

    var body: some View {
        NavigationView {
            Form {
                TextField("Título", text: $notaTitulo)
                TextField("Descripción", text: $notaDescripcion)
            }
            .navigationTitle("Nueva Tarea")
            .toolbar {
                ToolbarItem(placement: .confirmationAction) {
                    Button("Guardar") {
                        let nuevaTarea = Tarea(
                            titulo: notaTitulo,
                            descripcion: notaDescripcion
                        )
                        onAgregar(nuevaTarea)
                        dismiss()
                    }
                    .disabled(notaTitulo.isEmpty)
                }

                ToolbarItem(placement: .cancellationAction) {
                    Button("Cancelar") {
                        dismiss()
                    }
                }
            }
        }
    }
}
