//
//  ContentView.swift
//  exp2
//
//  Created by roger on 11/04/25.
//

import SwiftUI

/*
 Ejercicio: App de Películas Favoritas

 Objetivo:

 Crear una aplicación que permita visualizar, agregar, editar y filtrar películas favoritas. La app utilizará Stacks, NavigationView, NavigationLinks, List, Sheets, SwipeActions, Pickers y estructuras de datos que conformen el protocolo Identifiable.

 Descripción del ejercicio:

 Se desarrollará una aplicación que muestre una lista de películas favoritas (por ejemplo, “Interstellar”, “Orgullo y prejuicio”, etc.). Al pulsar sobre una película, se navegará a una vista de detalle que muestre información adicional como el director, el año, una pequeña reseña y la calificación. También se podrá agregar una nueva película mediante un formulario en una hoja (Sheet), editar películas existentes, eliminar con swipe y aplicar filtros por estado de visualización.

 Requisitos técnicos:

 Modelo de datos:

     •    Crea una estructura Pelicula que cumpla con el protocolo Identifiable.
     •    Incluye las siguientes propiedades:
     •    id (usa UUID())
     •    titulo
     •    director
     •    anio
     •    resena
     •    calificacion (número entero del 1 al 5)
     •    vista (valor booleano)
 Vista principal (ContentView):
     •    Usa un NavigationView para envolver el contenido.
     •    Agrega un Picker para filtrar películas por estado:
     •    Todas
     •    Solo vistas
     •    Solo no vistas
     •    Usa una List para recorrer el arreglo filtrado de películas.
     •    Cada fila usa un NavigationLink que lleva a una vista de detalle.
     •    Añade swipe actions a cada fila:
     •    Deslizar a la izquierda: eliminar la película.
     •    Deslizar a la derecha: marcar como vista/no vista.
     •    En la barra de navegación, coloca un botón “Agregar” que active un Sheet.

 Vista de detalle:
     •    Muestra información completa de la película seleccionada:
     •    Título
     •    Director
     •    Año de estreno
     •    Reseña
     •    Calificación (puede representarse con estrellas usando Image(systemName:))
     •    Estado: vista/no vista
     •    Incluye un botón “Editar” que muestra un Sheet con el formulario precargado.

 Agregar y editar películas:
     •    El formulario debe usar una combinación de TextField, TextEditor, Stepper (para la calificación), y un Toggle (para el estado de vista).
     •    Valida que los campos obligatorios no estén vacíos.
     •    Al guardar, la película se añade o se actualiza en el arreglo y se cierra el Sheet.

 Manejo de estado:
     •    Utiliza @State para el arreglo de películas y para controlar la presentación del Sheet.
     •    Usa variables de estado adicionales para:
     •    Controlar el formulario.
     •    Saber si se está agregando o editando una película.
     •    Controlar el filtro seleccionado (todas, vistas, no vistas).

 */

struct ContentView: View {
    @State var peliculas: [Pelicula] = Pelicula.ejemplos
    @State var mostrandoSheet = false
    @State var peliculaParaEditar: Pelicula? = nil
    @State var filtroSeleccionado: FiltroEstado = .todas

    enum FiltroEstado: String, CaseIterable, Identifiable {
        case todas = "Todas"
        case vistas = "Vistas"
        case noVistas = "No Vistas"
        var id: String { self.rawValue }
    }
    var peliculasFiltradas: [Pelicula] {
        switch filtroSeleccionado {
        case .todas:
            return peliculas
        case .vistas:
            return peliculas.filter { $0.vista }
        case .noVistas:
            return peliculas.filter { !$0.vista }
        }
    }

    var body: some View {
        NavigationView {
            VStack {
                Picker("Filtrar por", selection: $filtroSeleccionado) {
                    ForEach(FiltroEstado.allCases) { estado in
                        Text(estado.rawValue).tag(estado)
                    }
                }
                .pickerStyle(.segmented)
                .padding(.horizontal)

                List {
                    ForEach(peliculasFiltradas) { pelicula in
                        NavigationLink(
                            destination: DetallePeliculaView(
                                pelicula: pelicula,
                                onEditar: {
                                    self.peliculaParaEditar = pelicula
                                    self.mostrandoSheet = true
                                }
                            )
                        ) {
                            HStack {
                                VStack(alignment: .leading) {
                                    Text(pelicula.titulo).font(.headline)
                                    Text(pelicula.director).font(.subheadline)
                                        .foregroundColor(.gray)
                                }
                                Spacer()
                                if pelicula.vista {
                                    Image(systemName: "eye.fill")
                                        .foregroundColor(.blue)
                                }
                            }
                        }
                        .swipeActions(edge: .leading, allowsFullSwipe: true) {
                            Button {
                                toggleVista(for: pelicula)
                            } label: {
                                Label(
                                    pelicula.vista
                                        ? "Marcar No Vista" : "Marcar Vista",
                                    systemImage: pelicula.vista
                                        ? "eye.slash.fill" : "eye.fill"
                                )
                            }
                            .tint(pelicula.vista ? .gray : .blue)
                        }
                        .swipeActions(edge: .trailing, allowsFullSwipe: true) {
                            Button(role: .destructive) {
                                eliminarPelicula(pelicula)
                            } label: {
                                Label("Eliminar", systemImage: "trash.fill")
                            }
                        }
                    }
                }
                .listStyle(.plain)
            }
            .navigationTitle("Películas Favoritas")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button {
                        peliculaParaEditar = nil
                        mostrandoSheet = true
                    } label: {
                        Label(
                            "Agregar Película",
                            systemImage: "plus.circle.fill"
                        )
                    }
                }
            }
            .sheet(isPresented: $mostrandoSheet) {
                DetailView(
                    peliculaAEditar: peliculaParaEditar,
                    onGuardar: { peliculaGuardada in
                        guardarPelicula(peliculaGuardada)
                        mostrandoSheet = false
                    }
                )
            }
        }
    }

    func guardarPelicula(_ pelicula: Pelicula) {
        if let index = peliculas.firstIndex(where: { $0.id == pelicula.id }) {
            peliculas[index] = pelicula
        } else {
            peliculas.append(pelicula)
        }
    }

    func eliminarPelicula(_ pelicula: Pelicula) {
        if let index = peliculas.firstIndex(where: { $0.id == pelicula.id }) {
            peliculas.remove(at: index)
        }
    }

    func toggleVista(for pelicula: Pelicula) {
        if let index = peliculas.firstIndex(where: { $0.id == pelicula.id }) {
            peliculas[index].vista.toggle()
        }
    }
}

#Preview {
    ContentView()
}
