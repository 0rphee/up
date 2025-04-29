//
//  ContentView.swift
//  examen3
//
//  Created by roger on 11/04/25.
//

import SwiftUI

struct ContentView: View {
    @State var peliculas: [Pelicula]
    @State private var mostrarFormulario = false
    @State private var peliculaActual: Pelicula? = nil
    @State private var filtro = "Todas"

    var filtros = ["Todas", "Vistas", "No vistas"]

    var peliculasFiltradas: [Pelicula] {
        switch filtro {
        case "Vistas": return peliculas.filter { $0.vista }
        case "No vistas": return peliculas.filter { !$0.vista }
        default: return peliculas
        }
    }

    var body: some View {
        NavigationView {
            VStack {
                Picker("Filtro", selection: $filtro) {
                    ForEach(filtros, id: \.self) { Text($0) }
                }.pickerStyle(.segmented).padding()

                List {
                    ForEach(peliculasFiltradas) { pelicula in
                        navlink(pelicula: pelicula, peliculaActual: $peliculaActual, mostrarFormulario: $mostrarFormulario, peliculas: $peliculas)
                    }
                }
            }
            .navigationTitle("Películas")
            .toolbar {
                Button("Agregar") {
                    peliculaActual = nil
                    mostrarFormulario = true
                }
            }
            .sheet(isPresented: $mostrarFormulario) {
                FormularioPeliculaView(pelicula: peliculaActual) { nueva in
                    if let index = peliculas.firstIndex(where: {
                        $0.id == nueva.id
                    }) {
                        peliculas[index] = nueva
                    } else {
                        peliculas.append(nueva)
                    }
                    mostrarFormulario = false
                }
            }
        }
    }
}

struct navlink: View {
    var pelicula: Pelicula
    @Binding var peliculaActual: Pelicula?
    @Binding var mostrarFormulario: Bool
    @Binding var peliculas: [Pelicula]
    var body: some View {
        NavigationLink(
            destination: DetallePeliculaView(
                pelicula: pelicula,
                onEditar: { p in
                    peliculaActual = p
                    mostrarFormulario = true
                }
            )
        ) {
            Text(pelicula.titulo)
        }
        .swipeActions(edge: .leading) {
            Button {
                if let index = peliculas.firstIndex(
                    of: pelicula
                ) {
                    peliculas[index].vista.toggle()
                }
            } label: {
                Label(
                    pelicula.vista ? "No vista" : "Vista",
                    systemImage: "eye"
                )
            }.tint(.blue)
        }
        .swipeActions {
            Button(role: .destructive) {
                peliculas.removeAll { $0.id == pelicula.id }
            } label: {
                Label("Eliminar", systemImage: "trash")
            }
        }
    }
}



#Preview {
    ContentView(peliculas: Pelicula.ejemplos)
}
