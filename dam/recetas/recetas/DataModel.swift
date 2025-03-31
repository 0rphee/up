//
//  DataModel.swift
//  recetas
//
//  Created by roger on 28/03/25.
//

import Foundation

// Atributos: codable, encodable, decodable

//RecetaModel: Crea una estructura que contenga al menos:
//id (UUID)
//nombre (String)
//imagen (String, nombre de la imagen)
//ingredientes (Array de String)
//instrucciones (String)
//dificultad (String o enum, por ejemplo: "Fácil", "Media", "Difícil")
//CategoriaModel: Crea otra estructura para las categorías, con:
//id (UUID)
//nombre (String)
//recetas (Array de RecetaModel)
//

enum Difficulty: String {
    case difficult = "Difícil"
    case medium = "Medio"
    case easy = "Fácil"
}

struct RecipeModel: Identifiable {
    var id = UUID()
    let name: String
    let image: String
    let ingredients: [String]
    let instructions: String
    let difficulty: Difficulty
}

struct CategoryModel: Identifiable {
    var id = UUID()
    let name: String
    let recipes: [RecipeModel]
}

let tacos = RecipeModel(
    name: "taco al pastor", image: "comida",
    ingredients: ["carne", "tortilla"], instructions: "cocinar",
    difficulty: .difficult)

let categories = [
    CategoryModel(
        name: "tacos",
        recipes: [
            tacos
        ])
    //    PasilloModel(
    //        nombre: "Enlatados",
    //        productos: [
    //            DataModel(
    //                cantidad: 4.0, producto: "Atun", precio: 35.0, imagen: "atun")
    //        ]),
    //    PasilloModel(
    //        nombre: "Bebidas",
    //        productos: [
    //            DataModel(
    //                cantidad: 6, producto: "Coca Cola Vidrio", precio: 20.0,
    //                imagen: "coca")
    //        ]),
    //    PasilloModel(
    //        nombre: "Lácteos",
    //        productos: [
    //            DataModel(
    //                cantidad: 3, producto: "Leche Alpura Entera", precio: 40,
    //                imagen: "leche")
    //        ]),
    //    PasilloModel(
    //        nombre: "Salchichonería",
    //        productos: [
    //            DataModel(
    //                cantidad: 1, producto: "Queso Manchego", precio: 78,
    //                imagen: "queso")
    //        ]),
    //    PasilloModel(
    //        nombre: "Electronica",
    //        productos: [
    //            DataModel(
    //                cantidad: 1, producto: "Tarjeta Play Store", precio: 100,
    //                imagen: "play")
    //        ]),
    //    PasilloModel(
    //        nombre: "Verduras",
    //        productos: [
    //            DataModel(
    //                cantidad: 0.5, producto: "Zanaoria", precio: 7.5,
    //                imagen: "zanahoria")
    //        ]),
    //    PasilloModel(
    //        nombre: "Frutas",
    //        productos: [
    //            DataModel(
    //                cantidad: 1, producto: "Papaya", precio: 16, imagen: "papaya")
    //        ]),
    //    PasilloModel(
    //        nombre: "Congelados",
    //        productos: [
    //            DataModel(
    //                cantidad: 3, producto: "Helado Napolitano", precio: 70,
    //                imagen: "helado")
    //        ]),
    //    PasilloModel(
    //        nombre: "Condimentos",
    //        productos: [
    //            DataModel(
    //                cantidad: 5, producto: "Rico Pollo", precio: 12, imagen: "rico")
    //        ]),
    //    PasilloModel(
    //        nombre: "Blancos",
    //        productos: [
    //            DataModel(
    //                cantidad: 1, producto: "Jabón Zote", precio: 21.5,
    //                imagen: "zote")
    //        ]),
]
