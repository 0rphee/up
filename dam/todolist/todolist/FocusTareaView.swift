//
//  DetalleTareaView.swift
//  todolist
//
//  Created by roger on 04/04/25.
//

import SwiftUI

struct FocusTareaView: View {
    let tareaActual: Tarea
    var body: some View {
        VStack(alignment: .leading, spacing: 5) {
            Text(tareaActual.titulo).font(.largeTitle).bold()
            Text(tareaActual.descripcion).font(.body)
            Spacer()
        }
        .padding()
        .navigationTitle("Focus Tarea")
    }
}
