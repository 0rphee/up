//
//  ContentView.swift
//  todolist
//
//  Created by roger on 04/04/25.
//

import SwiftUI

struct ContentView: View {
    @State private var listaTareas: [Tarea] = [
        Tarea(titulo: "Entrega 6 Lógica", descripcion: "pg. 199-222"),
        Tarea(titulo: "Reporte Física 2", descripcion: "martes 16"),
        Tarea(titulo: "Ex. Final", descripcion: "estudiar"),
    ]
    @State private var mostrarSheet = false

    var body: some View {
        NavigationView {
            List(listaTareas) { tarea in
                NavigationLink(
                    destination: FocusTareaView(tareaActual: tarea)
                ) { Text(tarea.titulo) }
            }
            .navigationTitle("Todo List")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button(action: {
                        mostrarSheet = true
                    }) {
                        Image(systemName: "plus")
                    }
                }
            }
            .sheet(isPresented: $mostrarSheet) {
                AgregarTareaView { nuevaTarea in
                    listaTareas.append(nuevaTarea)
                }
            }
        }
    }
}

#Preview {
    ContentView()
}
