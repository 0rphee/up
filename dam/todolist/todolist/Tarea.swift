//
//  Tarea.swift
//  todolist
//
//  Created by roger on 04/04/25.
//

import Foundation

struct Tarea: Identifiable {
    let id = UUID()
    var titulo: String
    var descripcion: String
}
