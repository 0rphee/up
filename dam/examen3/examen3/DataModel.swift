//
//  DataModel.swift
//  examen3
//
//  Created by roger on 11/04/25.
//

import Foundation

struct Pelicula: Identifiable, Equatable {
    let id: UUID
    var titulo: String
    var director: String
    var anio: Int
    var resena: String
    var calificacion: Int
    var vista: Bool
    
    init(id: UUID = UUID(), titulo: String, director: String, anio: Int, resena: String, calificacion: Int, vista: Bool) {
        self.id = id
        self.titulo = titulo
        self.director = director
        self.anio = anio
        self.resena = resena
        self.calificacion = calificacion
        self.vista = vista
    }

    static let interestellar = Pelicula(
        titulo: "Interstellar",
        director: "Christopher Nolan",
        anio: 2014,
        resena: "Viaje a estrellas",
        calificacion: 5,
        vista: true
    )
    static let orgullo = Pelicula(
        titulo: "Orgullo y Prejuicio",
        director: "Joe Wright",
        anio: 2005,
        resena: "Adaptación",
        calificacion: 4,
        vista: true
    )
    static let dune = Pelicula(
        titulo: "Dune",
        director: "Denis Villeneuve",
        anio: 2020,
        resena: "Dune",
        calificacion: 4,
        vista: false
    )

    static let ejemplos = [
        interestellar,
        orgullo,
        dune,
    ]
}
