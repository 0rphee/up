//
//  ViewModel.swift
//  exp2
//
//  Created by roger on 11/04/25.
//

import Foundation

struct Pelicula: Identifiable{
    var id = UUID()
    var titulo: String
    var director: String
    var anio: Int
    var resena: String
    var calificacion: Int // 1 a 5
    var vista: Bool
    
    static let interestellar = Pelicula(titulo: "Interstellar", director: "Christopher Nolan", anio: 2014, resena: "Viaje a estrellas", calificacion: 5, vista: true)
    static let orgullo = Pelicula(titulo: "Orgullo y Prejuicio", director: "Joe Wright", anio: 2005, resena: "Adaptación", calificacion: 4, vista: true)
    static let dune = Pelicula(titulo: "Dune", director: "Denis Villeneuve", anio: 2020, resena: "Dune", calificacion: 4, vista: false)

    static let ejemplos = [
        interestellar,
        orgullo,
        dune,
    ]
}

